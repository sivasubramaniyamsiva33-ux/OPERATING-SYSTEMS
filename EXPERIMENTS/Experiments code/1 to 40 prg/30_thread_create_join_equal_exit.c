/*
 * Experiment 30: Demonstrate thread related concepts -
 * (i) create (ii) join (iii) equal (iv) exit.
 * Compile: gcc 30_thread_create_join_equal_exit.c -o exp30 -lpthread
 * Run:     ./exp30
 */
#include <stdio.h>
#include <pthread.h>

void *threadFunction(void *arg) {
    long id = (long) arg;
    printf("Thread %ld: started, thread ID = %lu\n", id, (unsigned long) pthread_self());
    printf("Thread %ld: exiting using pthread_exit()\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    /* (i) create */
    pthread_create(&t1, NULL, threadFunction, (void *) 1);
    pthread_create(&t2, NULL, threadFunction, (void *) 2);

    /* (iii) equal */
    if (pthread_equal(t1, t2))
        printf("Main: t1 and t2 are the same thread.\n");
    else
        printf("Main: t1 and t2 are different threads.\n");

    /* (ii) join */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main: both threads joined successfully.\n");

    /* (iv) exit */
    pthread_exit(NULL);
}
