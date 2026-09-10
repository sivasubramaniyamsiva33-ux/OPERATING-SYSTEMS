/*
 * Experiment 1: Create a new process using fork(). Get the process
 * identifier of the currently running process and its parent using
 * system calls and display them.
 * Compile: gcc 01_create_process_pid.c -o exp1
 * Run:     ./exp1
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    printf("Before fork: PID = %d, Parent PID = %d\n", getpid(), getppid());

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child Process : PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        sleep(1); /* let child print first */
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
