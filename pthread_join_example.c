#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 4


void *threadFunc(void *arg) {
  int *p = (int*) arg;
  int myNum = *p;
  printf("Thread number %d\n", myNum);
  return 0;
}


int main(void) {
  int counter;
  pthread_t tid[NUM_THREADS];
  for(counter = 0; counter < NUM_THREADS; counter++) {
    pthread_create(&tid[counter], NULL, threadFunc, &counter);
  }
  for(counter = 0; counter < NUM_THREADS; counter ++) {
    pthread_join(tid[counter], NULL);
  }
  return 0;
}


/*
One of the possible outcome would be

Thread number 2
Thread number 0
Thread number 2
Thread number 3

what happened here is that when the children thread was excuting for the counter 1,
The main thread changed the value of value of counter to 2, demonstrating threads within a process share same address space despite having different execution context.

*/
