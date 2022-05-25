#include <unistd.h>
#include<sys/wait.h>
#include<stdio.h>

int main(void) {
  
  int cid = fork();
 
  
  if (cid == 0) {
      // I'm in the child
    for (int i=1; i<10; i++) {
      printf("Iterating: %d\n", i);
      sleep(1);
    }
    
  } else {
    wait(NULL);
    printf("Ends waiting");
    
  }
  
  return 0;
}

