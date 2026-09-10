/*
 * Experiment 26: File management operations - create, rename,
 * delete, check existence.
 * Compile: gcc 26_file_management_operations.c -o exp26
 * Run:     ./exp26
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int choice;
    char name1[100], name2[100];

    while (1) {
        printf("\n--- File Management Operations ---\n");
        printf("1. Create File\n2. Rename File\n3. Delete File\n4. Check File Existence\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter file name to create: ");
                scanf("%99s", name1);
                FILE *fp = fopen(name1, "w");
                if (fp) { printf("File created.\n"); fclose(fp); }
                else perror("fopen");
                break;
            }
            case 2: {
                printf("Enter existing file name: ");
                scanf("%99s", name1);
                printf("Enter new file name: ");
                scanf("%99s", name2);
                if (rename(name1, name2) == 0)
                    printf("File renamed successfully.\n");
                else
                    perror("rename");
                break;
            }
            case 3: {
                printf("Enter file name to delete: ");
                scanf("%99s", name1);
                if (remove(name1) == 0)
                    printf("File deleted successfully.\n");
                else
                    perror("remove");
                break;
            }
            case 4: {
                printf("Enter file name to check: ");
                scanf("%99s", name1);
                if (access(name1, F_OK) == 0)
                    printf("File exists.\n");
                else
                    printf("File does not exist.\n");
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
