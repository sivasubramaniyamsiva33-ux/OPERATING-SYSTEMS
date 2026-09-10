/*
 * Experiment 20: Simulate the Reader-Writer problem using semaphores.
 * Compile: gcc 20_reader_writer_semaphore.c -o exp20 -lpthread
 * Run:     ./exp20
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t wrt;
pthread_mutex_t mutex;
int readCount = 0;
int sharedData = 0;

void *reader(void *arg) {
    int id = *(int *) arg;

    pthread_mutex_lock(&mutex);
    readCount++;
    if (readCount == 1)
        sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);

    printf("Reader %d: read value = %d\n", id, sharedData);
    sleep(1);

    pthread_mutex_lock(&mutex);
    readCount--;
    if (readCount == 0)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *writer(void *arg) {
    int id = *(int *) arg;

    sem_wait(&wrt);
    sharedData++;
    printf("Writer %d: wrote value = %d\n", id, sharedData);
    sleep(1);
    sem_post(&wrt);

    return NULL;
}

int main() {
    pthread_t r[3], w[2];
    int rid[3] = {1, 2, 3}, wid[2] = {1, 2};

    sem_init(&wrt, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 3; i++)
        pthread_create(&r[i], NULL, reader, &rid[i]);
    for (int i = 0; i < 2; i++)
        pthread_create(&w[i], NULL, writer, &wid[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(r[i], NULL);
    for (int i = 0; i < 2; i++)
        pthread_join(w[i], NULL);

    sem_destroy(&wrt);
    pthread_mutex_destroy(&mutex);

    return 0;
}
