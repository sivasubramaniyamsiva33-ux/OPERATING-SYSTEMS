/*
 * Experiment 15: Organise files using a two level directory structure.
 * Compile: gcc 15_two_level_directory.c -o exp15
 * Run:     ./exp15
 */
#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_FILES 20
#define MAX_LEN 30

char users[MAX_USERS][MAX_LEN];
char files[MAX_USERS][MAX_FILES][MAX_LEN];
int fileCount[MAX_USERS];
int userCount = 0;

int findUser(char *uname) {
    for (int i = 0; i < userCount; i++)
        if (strcmp(users[i], uname) == 0)
            return i;
    return -1;
}

void createUser(char *uname) {
    if (findUser(uname) != -1) {
        printf("User already exists.\n");
        return;
    }
    strcpy(users[userCount], uname);
    fileCount[userCount] = 0;
    userCount++;
    printf("User '%s' created.\n", uname);
}

void createFile(char *uname, char *fname) {
    int u = findUser(uname);
    if (u == -1) { printf("User not found.\n"); return; }
    strcpy(files[u][fileCount[u]++], fname);
    printf("File '%s' created under user '%s'.\n", fname, uname);
}

void listFiles(char *uname) {
    int u = findUser(uname);
    if (u == -1) { printf("User not found.\n"); return; }
    printf("\nFiles for user '%s':\n", uname);
    for (int i = 0; i < fileCount[u]; i++)
        printf("%d. %s\n", i + 1, files[u][i]);
}

int main() {
    int choice;
    char uname[MAX_LEN], fname[MAX_LEN];

    while (1) {
        printf("\n--- Two Level Directory ---\n");
        printf("1. Create User\n2. Create File\n3. List Files\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter user name: ");
                scanf("%29s", uname);
                createUser(uname);
                break;
            case 2:
                printf("Enter user name: ");
                scanf("%29s", uname);
                printf("Enter file name: ");
                scanf("%29s", fname);
                createFile(uname, fname);
                break;
            case 3:
                printf("Enter user name: ");
                scanf("%29s", uname);
                listFiles(uname);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
