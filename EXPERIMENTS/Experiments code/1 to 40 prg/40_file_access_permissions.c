/*
 * Experiment 40: Illustrate File Access Permissions and different
 * types of users in Linux (view/change with stat and chmod).
 * Compile: gcc 40_file_access_permissions.c -o exp40
 * Run:     ./exp40
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void printPermissions(mode_t mode) {
    printf("Permissions: ");
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

int main() {
    char filename[100];
    int choice, permValue;

    printf("Enter file name: ");
    scanf("%99s", filename);

    while (1) {
        printf("\n--- File Access Permission Manager ---\n");
        printf("1. View current permissions\n2. Change permissions (chmod)\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        struct stat st;
        switch (choice) {
            case 1:
                if (stat(filename, &st) == 0) {
                    printPermissions(st.st_mode);
                    printf("Owner UID: %d, Group GID: %d\n", st.st_uid, st.st_gid);
                } else {
                    perror("stat");
                }
                break;
            case 2:
                printf("Enter new permission value in octal (e.g., 644, 755): ");
                scanf("%o", &permValue);
                if (chmod(filename, permValue) == 0)
                    printf("Permissions changed successfully.\n");
                else
                    perror("chmod");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
