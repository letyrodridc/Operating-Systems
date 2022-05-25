#include <pthread.h>
#include <iostream>
#include <unistd.h>
using namespace std;

pthread_t threads[2];
int counter;
pthread_mutex_t lock;

void *print_numbers(void* arg) {
	cout << "Waiting outside" << endl;
	pthread_mutex_lock(&lock);

	cout << "In a thread," << endl;
	for (int i = 0; i < 100; i++) {
		cout << i << " ";
		sleep(0.1);
	}

	pthread_mutex_unlock(&lock);	

}

int main() {


	cout << "Starting main thread" << endl;

	if (pthread_mutex_init(&lock, NULL) != 0) {
		cout << "Failed mutex initizalization " << endl;
		exit(-1);
	}

	for (int i=0; i < 2; i++) {
		pthread_create(&(threads[i]),NULL, &print_numbers, NULL);
	}

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_mutex_destroy(&lock);

	return 0;
}