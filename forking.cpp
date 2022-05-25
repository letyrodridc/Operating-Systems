#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fstream>

using namespace std;


int main(void)
{
	pid_t process_id;
	pid_t p_process_id;
	pid_t parent_process_id;
	ofstream data;

	parent_process_id = getpid();
	
	fork();

	process_id = getpid();
	
	p_process_id = getppid();


	printf("The process id: %d\n",process_id);
	printf("The process id of parent function: %d\n",p_process_id);

	sleep(15);
	if (process_id == parent_process_id) {
		printf("Parent is sleeping: %d\n", parent_process_id);
		//sleep(60);
		return 0;
	} 



	
	data.open("test.txt");

	for (int i = 0 ; i < 10000000; i++) {
		int j = i*i;	
		data << "Valor:" << j << endl;	
	}

	data.close();

	p_process_id = getppid();
	printf("The process id of parent function: %d\n",p_process_id);


	return 0;
}