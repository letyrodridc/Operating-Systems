#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

using namespace std;

void *wait(void *t) {
	int i;
	long tid;

	tid = (long) t;

	sleep(1);

	cout << "Sleeping in thread" << endl;
	cout << "Thread with id: " << tid << "... exiting " << endl;

	pthread_exit(NULL);
}
int main() {
	int rc;
	int i;

	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	void *status;


	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0; i < NUM_THREADS; i++) {
		cout << "main() : creating thread, " << i << endl;
		rc = pthread_create(&threads[i], &attr, wait, (void*) i);

		if (rc) {
			cout << "Error: unable to create thread," << rc << endl;
			exit(-1);
		}
	}

	pthread_attr_destroy(&attr);

	for (i=0; i< NUM_THREADS; i++) {
		rc = pthread_join(threads[i], &status);

		if (rc) {
			cout << "Error: unable to join,"<< rc<< endl;
			exit(-1);
		}

		cout << "Maint: complete thread id: "<< i;
		cout << " existing with status: " << status << endl;

	}

	cout << "Main: program exiting. " << endl;
	pthread_exit(NULL);
}