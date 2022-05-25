#include <semaphore.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

sem_t mutex1, mutex2;
int result = 5;

void* multiplicate(void*) {
	sem_wait(&mutex1);
	result *= 10;
	sem_post(&mutex2);
	sem_post(&mutex1);
}


void* add(void*) {
	sem_wait(&mutex2);
	result += 5;
	sem_post(&mutex2);
}

int main() {
	pthread_t t1, t2;

	sem_init(&mutex1, 0, 0);
	sem_init(&mutex2, 0, 0);

	pthread_create(&t1, NULL, multiplicate, NULL);
	pthread_create(&t2, NULL, add, NULL);
	sem_post(&mutex1);

	pthread_join(t1,NULL);
	pthread_join(t2, NULL);
	

	cout << result << endl;

	sem_destroy(&mutex1);
	sem_destroy(&mutex2);
}