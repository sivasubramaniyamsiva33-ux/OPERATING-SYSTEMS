/*
 * Experiment 25: I/O system calls of UNIX (fcntl, lseek, stat,
 * opendir, readdir).
 * Compile: gcc 25_unix_io_syscalls.c -o exp25
 * Run:     ./exp25
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

int main() {
    int choice;
    char name[100];

    while (1) {
        printf("\n--- UNIX I/O System Calls Demo ---\n");
        printf("1. fcntl (get file status flags)\n2. lseek (find file size)\n3. stat (file info)\n4. opendir/readdir (list directory)\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter file name: ");
                scanf("%99s", name);
                int fd = open(name, O_RDONLY);
                if (fd < 0) { perror("open"); break; }
                int flags = fcntl(fd, F_GETFL);
                printf("File descriptor flags: %d\n", flags);
                close(fd);
                break;
            }
            case 2: {
                printf("Enter file name: ");
                scanf("%99s", name);
                int fd = open(name, O_RDONLY);
                if (fd < 0) { perror("open"); break; }
                off_t pos = lseek(fd, 0, SEEK_END);
                printf("File size (via lseek): %ld bytes\n", (long) pos);
                close(fd);
                break;
            }
            case 3: {
                printf("Enter file name: ");
                scanf("%99s", name);
                struct stat st;
                if (stat(name, &st) == 0) {
                    printf("Size: %ld bytes\n", (long) st.st_size);
                    printf("Permissions: %o\n", st.st_mode & 0777);
                    printf("Last modified: %s", ctime(&st.st_mtime));
                } else {
                    perror("stat");
                }
                break;
            }
            case 4: {
                printf("Enter directory name: ");
                scanf("%99s", name);
                DIR *dir = opendir(name);
                if (dir == NULL) { perror("opendir"); break; }
                struct dirent *entry;
                printf("Contents of '%s':\n", name);
                while ((entry = readdir(dir)) != NULL)
                    printf("%s\n", entry->d_name);
                closedir(dir);
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
