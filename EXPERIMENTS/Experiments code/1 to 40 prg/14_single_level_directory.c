/*
 * Experiment 14: Organise files using a single level directory.
 * Compile: gcc 14_single_level_directory.c -o exp14
 * Run:     ./exp14
 */
#include <stdio.h>
#include <string.h>

#define MAX_FILES 20
#define MAX_LEN 30

char directory[MAX_FILES][MAX_LEN];
int fileCount = 0;

void createFile(char *name) {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(directory[i], name) == 0) {
            printf("File already exists.\n");
            return;
        }
    }
    strcpy(directory[fileCount++], name);
    printf("File '%s' created.\n", name);
}

void deleteFile(char *name) {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(directory[i], name) == 0) {
            for (int j = i; j < fileCount - 1; j++)
                strcpy(directory[j], directory[j + 1]);
            fileCount--;
            printf("File '%s' deleted.\n", name);
            return;
        }
    }
    printf("File not found.\n");
}

void listFiles() {
    printf("\nFiles in directory:\n");
    for (int i = 0; i < fileCount; i++)
        printf("%d. %s\n", i + 1, directory[i]);
}

void searchFile(char *name) {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(directory[i], name) == 0) {
            printf("File '%s' found.\n", name);
            return;
        }
    }
    printf("File '%s' not found.\n", name);
}

int main() {
    int choice;
    char name[MAX_LEN];

    while (1) {
        printf("\n--- Single Level Directory ---\n");
        printf("1. Create File\n2. Delete File\n3. Search File\n4. List Files\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%29s", name);
                createFile(name);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%29s", name);
                deleteFile(name);
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%29s", name);
                searchFile(name);
                break;
            case 4:
                listFiles();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
