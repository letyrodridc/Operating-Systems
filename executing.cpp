#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

int main(void) {
	int parentID = getpid();
	char prgname[1024];
	cin >> prgname;

	int cid = fork();

	if (cid == 0) {
		// I'm in the child
		execlp(prgname, prgname, 0, (char *) NULL);
		printf("I didn't find the program %s\n", prgname);
	} else {
		// Parent si waiting for the child to finish
		sleep(1);
		waitpid(cid, 0,0);
		printf("Program %s finished \n", prgname);
	}

}