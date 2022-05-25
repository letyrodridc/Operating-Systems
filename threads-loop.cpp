#include <pthread.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

void *PrintHello(void *threadid) {
  long tid;
  tid = (long)threadid;
  cout << "Hello World! Thread ID, " << tid << endl;
  sleep(60);
  pthread_exit(NULL);
}


int main() {
  pthread_t threads;
  int rc;
  int i = 100;
  
  cout << getpid() << endl;
  cout << "main() : creating thread, " << i << endl;
  rc = pthread_create(&threads, NULL, PrintHello, (void*) i);
    
  if (rc) {
    cout << "Error: unable to create thread, " << rc << endl;
    exit(-1);
  }
  
  pthread_exit(NULL);
  return 0;
}

