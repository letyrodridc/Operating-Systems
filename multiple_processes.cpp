#include <unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include <stdlib.h>  


void iterations() {
    for (int i=0; i<3; i++) {
      printf("Iteration: %d\n", i);
      sleep(1);
    }

}

int main(void) {
 
  pid_t super_parent = getpid();
  
  for (int i=1; i<10; i++) {
      int cid = fork();
 
      if (cid == 0)
        i = 10;
  }
  iterations();
  wait(NULL);
  if (getpid() == super_parent){
      wait(NULL);
      printf("Ends waiting");
  }
  
  return 0;
}

