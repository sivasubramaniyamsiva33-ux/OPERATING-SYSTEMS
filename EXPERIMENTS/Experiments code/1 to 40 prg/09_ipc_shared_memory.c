/*
 * Experiment 9: Inter-process communication using shared memory.
 * Child process writes data, parent process reads it back.
 * Compile: gcc 09_ipc_shared_memory.c -o exp9
 * Run:     ./exp9
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
    key_t key = ftok(".", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        /* Child: writer */
        char *str = (char *) shmat(shmid, NULL, 0);
        printf("Child: Enter data to write to shared memory: ");
        fgets(str, 1024, stdin);
        printf("Child: Data written to shared memory.\n");
        shmdt(str);
        exit(0);
    } else {
        wait(NULL);
        /* Parent: reader */
        char *str = (char *) shmat(shmid, NULL, 0);
        printf("Parent: Data read from shared memory: %s\n", str);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
