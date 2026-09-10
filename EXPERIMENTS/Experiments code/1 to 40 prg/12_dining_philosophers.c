/*
 * Experiment 12: Simulate the Dining Philosophers problem.
 * Compile: gcc 12_dining_philosophers.c -o exp12 -lpthread
 * Run:     ./exp12
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t chopstick[N];
pthread_t philosophers[N];

void *philosopher(void *num) {
    int id = *(int *) num;
    int left = id;
    int right = (id + 1) % N;

    printf("Philosopher %d is thinking.\n", id);
    sleep(1);

    /* Avoid deadlock: last philosopher picks up right chopstick first */
    if (id == N - 1) {
        sem_wait(&chopstick[right]);
        sem_wait(&chopstick[left]);
    } else {
        sem_wait(&chopstick[left]);
        sem_wait(&chopstick[right]);
    }

    printf("Philosopher %d is eating.\n", id);
    sleep(1);

    sem_post(&chopstick[left]);
    sem_post(&chopstick[right]);

    printf("Philosopher %d finished eating and put down chopsticks.\n", id);
    return NULL;
}

int main() {
    int ids[N];

    for (int i = 0; i < N; i++)
        sem_init(&chopstick[i], 0, 1);

    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(philosophers[i], NULL);

    for (int i = 0; i < N; i++)
        sem_destroy(&chopstick[i]);

    return 0;
}
