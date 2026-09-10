/*
 * Experiment 24: Demonstrate UNIX system calls for file management
 * (creat, open, read, write, close, unlink).
 * Compile: gcc 24_unix_file_management_syscalls.c -o exp24
 * Run:     ./exp24
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, choice;
    char filename[50], data[100];

    while (1) {
        printf("\n--- UNIX File Management System Calls ---\n");
        printf("1. Create File\n2. Write to File\n3. Read from File\n4. Delete File\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%49s", filename);
                fd = creat(filename, 0644);
                if (fd < 0) perror("creat");
                else { printf("File created.\n"); close(fd); }
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%49s", filename);
                getchar();
                printf("Enter data to write: ");
                fgets(data, sizeof(data), stdin);
                fd = open(filename, O_WRONLY | O_APPEND);
                if (fd < 0) {
                    perror("open");
                } else {
                    write(fd, data, strlen(data));
                    close(fd);
                    printf("Data written.\n");
                }
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%49s", filename);
                fd = open(filename, O_RDONLY);
                if (fd < 0) {
                    perror("open");
                } else {
                    int n;
                    char buf[256];
                    while ((n = read(fd, buf, sizeof(buf) - 1)) > 0) {
                        buf[n] = '\0';
                        printf("%s", buf);
                    }
                    close(fd);
                }
                break;
            case 4:
                printf("Enter file name: ");
                scanf("%49s", filename);
                if (unlink(filename) == 0)
                    printf("File deleted.\n");
                else
                    perror("unlink");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
