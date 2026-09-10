/*
 * Experiment 11: Illustrate the concept of multithreading.
 * Compile: gcc 11_multithreading_demo.c -o exp11 -lpthread
 * Run:     ./exp11
 */
#include <stdio.h>
#include <pthread.h>

void *print_message(void *arg) {
    char *message = (char *) arg;
    printf("Thread says: %s\n", message);
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    char *msg1 = "Hello from Thread 1";
    char *msg2 = "Hello from Thread 2";

    pthread_create(&t1, NULL, print_message, (void *) msg1);
    pthread_create(&t2, NULL, print_message, (void *) msg2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main: Both threads have finished execution.\n");
    return 0;
}
