/*
 * Experiment 13: Implementation of memory allocation strategy
 * (contiguous/fixed-partition allocation, first-available block).
 * Compile: gcc 13_memory_allocation_strategies.c -o exp13
 * Run:     ./exp13
 */
#include <stdio.h>

#define MAX 10

int main() {
    int blockSize[MAX], processSize[MAX], m, n;
    int allocation[MAX];

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter sizes of the memory blocks:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter sizes of the processes:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
