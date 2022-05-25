#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(void) {
	int parentID = getpid();
	int cid = fork();

	if (cid == 0) {
		sleep(5);
		printf("Quitting child\n");
		exit(0);
		printf(" Error! After exit call!\n" );
	} else {
		printf("Type any character to kill the child.\n");
		char answer[10];
		cin >> answer;
		if (! kill(cid, SIGKILL)) {
			printf("Killed the child.\n");
		}
	}
	return 0;
}