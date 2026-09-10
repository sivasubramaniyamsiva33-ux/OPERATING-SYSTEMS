/*
 * Experiment 10: Inter-process communication using a message queue.
 * Compile: gcc 10_ipc_message_queue.c -o exp10
 * Run:     ./exp10
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok(".", 66);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid < 0) {
        perror("msgget");
        exit(1);
    }

    pid_t pid = fork();
    struct msg_buffer message;

    if (pid == 0) {
        /* Child: sender */
        message.msg_type = 1;
        printf("Child: Enter a message to send: ");
        fgets(message.msg_text, sizeof(message.msg_text), stdin);
        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        printf("Child: Message sent.\n");
        exit(0);
    } else {
        wait(NULL);
        /* Parent: receiver */
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("Parent: Message received: %s\n", message.msg_text);
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
