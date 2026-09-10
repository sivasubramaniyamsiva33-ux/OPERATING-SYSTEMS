/*
 * Experiment 37: Simulate the First Come First Served (FCFS) disk
 * scheduling algorithm.
 * Compile: gcc 37_fcfs_disk_scheduling.c -o exp37
 * Run:     ./exp37
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int totalSeek = 0, curr = head;
    printf("\nSeek Sequence:\n%d\n", curr);
    for (int i = 0; i < n; i++) {
        totalSeek += abs(req[i] - curr);
        curr = req[i];
        printf("%d\n", curr);
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);
    printf("Average Seek Time = %.2f\n", (float) totalSeek / n);
    return 0;
}
