/*
 * Experiment 39: Simulate the C-SCAN disk scheduling algorithm.
 * Compile: gcc 39_cscan_disk_scheduling.c -o exp39
 * Run:     ./exp39
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int main() {
    int n, head, diskSize;

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

    qsort(req, n, sizeof(int), cmp);

    int totalSeek = 0, curr = head;
    printf("\nSeek Sequence (moving towards higher end, then wrap to 0):\n%d\n", curr);

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

    /* circular jump back to the start of the disk */
    totalSeek += (diskSize - 1);
    curr = 0;
    printf("%d (wrap around)\n", curr);

    for (int i = 0; i < n; i++) {
        if (req[i] < head) {
            totalSeek += abs(curr - req[i]);
            curr = req[i];
            printf("%d\n", curr);
        }
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);
    printf("Average Seek Time = %.2f\n", (float) totalSeek / n);
    return 0;
}
