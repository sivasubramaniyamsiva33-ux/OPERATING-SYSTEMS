/*
 * Experiment 16: Implementing random access file for processing
 * employee details.
 * Compile: gcc 16_random_access_employee_file.c -o exp16
 * Run:     ./exp16
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee emp;
    int choice, recNo;

    fp = fopen("employee.dat", "rb+");
    if (fp == NULL)
        fp = fopen("employee.dat", "wb+");

    if (fp == NULL) {
        perror("Could not open data file");
        return 1;
    }

    while (1) {
        printf("\n--- Random Access File - Employee Details ---\n");
        printf("1. Add/Update Employee\n2. Read Employee\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter record number (0-based): ");
                scanf("%d", &recNo);
                printf("Enter ID, Name, Salary: ");
                scanf("%d %29s %f", &emp.id, emp.name, &emp.salary);
                fseek(fp, recNo * sizeof(struct Employee), SEEK_SET);
                fwrite(&emp, sizeof(struct Employee), 1, fp);
                fflush(fp);
                printf("Record written successfully.\n");
                break;
            case 2:
                printf("Enter record number to read: ");
                scanf("%d", &recNo);
                fseek(fp, recNo * sizeof(struct Employee), SEEK_SET);
                if (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
                    printf("ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 3:
                fclose(fp);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
