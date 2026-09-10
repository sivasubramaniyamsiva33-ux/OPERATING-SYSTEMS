/*
 * Experiment 38: Simulate the SCAN disk scheduling algorithm.
 * Compile: gcc 38_scan_disk_scheduling.c -o exp38
 * Run:     ./exp38
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int main() {
    int n, head, diskSize, direction;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size: ");
    scanf("%d", &diskSize);
    printf("Enter direction (0 = towards 0, 1 = towards max): ");
    scanf("%d", &direction);

    qsort(req, n, sizeof(int), cmp);

    int totalSeek = 0, curr = head;
    printf("\nSeek Sequence:\n%d\n", curr);

    if (direction == 0) {
        for (int i = n - 1; i >= 0; i--) {
            if (req[i] < head) {
                totalSeek += abs(curr - req[i]);
                curr = req[i];
                printf("%d\n", curr);
            }
        }
        totalSeek += abs(curr - 0);
        curr = 0;
        printf("%d\n", curr);
        for (int i = 0; i < n; i++) {
            if (req[i] >= head) {
                totalSeek += abs(curr - req[i]);
                curr = req[i];
                printf("%d\n", curr);
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (req[i] >= head) {
                totalSeek += abs(curr - req[i]);
                curr = req[i];
                printf("%d\n", curr);
            }
        }
        totalSeek += abs(curr - (diskSize - 1));
        curr = diskSize - 1;
        printf("%d\n", curr);
        for (int i = n - 1; i >= 0; i--) {
            if (req[i] < head) {
                totalSeek += abs(curr - req[i]);
                curr = req[i];
                printf("%d\n", curr);
            }
        }
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);
    printf("Average Seek Time = %.2f\n", (float) totalSeek / n);
    return 0;
}
