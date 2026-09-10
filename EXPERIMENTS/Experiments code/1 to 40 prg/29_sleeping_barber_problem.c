/*
 * Experiment 29: Classical process synchronization problem -
 * the Sleeping Barber problem, using semaphores.
 * Compile: gcc 29_sleeping_barber_problem.c -o exp29 -lpthread
 * Run:     ./exp29
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define CHAIRS 5
#define NUM_CUSTOMERS 8

sem_t customers, barberSem, mutex;
int waiting = 0;

void *barberThread(void *arg) {
    for (int served = 0; served < NUM_CUSTOMERS; served++) {
        sem_wait(&customers);
        sem_wait(&mutex);
        waiting--;
        sem_post(&barberSem);
        sem_post(&mutex);

        printf("Barber is cutting hair.\n");
        sleep(2);
        printf("Barber finished a haircut.\n");
    }
    return NULL;
}

void *customerThread(void *arg) {
    int id = *(int *) arg;

    sem_wait(&mutex);
    if (waiting < CHAIRS) {
        waiting++;
        printf("Customer %d is waiting. Total waiting: %d\n", id, waiting);
        sem_post(&customers);
        sem_post(&mutex);
        sem_wait(&barberSem);
        printf("Customer %d is getting a haircut.\n", id);
    } else {
        printf("Customer %d left, no waiting chairs available.\n", id);
        sem_post(&mutex);
    }

    return NULL;
}

int main() {
    pthread_t barberT;
    pthread_t custT[NUM_CUSTOMERS];
    int ids[NUM_CUSTOMERS];

    sem_init(&customers, 0, 0);
    sem_init(&barberSem, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&barberT, NULL, barberThread, NULL);

    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        ids[i] = i + 1;
        pthread_create(&custT[i], NULL, customerThread, &ids[i]);
        sleep(1);
    }

    for (int i = 0; i < NUM_CUSTOMERS; i++)
        pthread_join(custT[i], NULL);

    pthread_join(barberT, NULL);

    sem_destroy(&customers);
    sem_destroy(&barberSem);
    sem_destroy(&mutex);

    return 0;
}
