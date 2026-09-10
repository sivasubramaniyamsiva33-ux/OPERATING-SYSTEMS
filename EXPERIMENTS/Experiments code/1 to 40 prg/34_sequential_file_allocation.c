/*
 * Experiment 34: Simulate the sequential (contiguous) file
 * allocation strategy, where a record can only be accessed by
 * reading all previous records.
 * Compile: gcc 34_sequential_file_allocation.c -o exp34
 * Run:     ./exp34
 */
#include <stdio.h>

#define MAX_BLOCKS 20

int main() {
    int disk[MAX_BLOCKS] = {0};
    int n, start, length, totalBlocks;

    printf("Enter total disk blocks (max %d): ", MAX_BLOCKS);
    scanf("%d", &totalBlocks);

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter start block and length for file %d: ", i + 1);
        scanf("%d %d", &start, &length);

        int canAllocate = 1;
        if (start + length > totalBlocks)
            canAllocate = 0;
        for (int j = start; canAllocate && j < start + length; j++)
            if (disk[j] == 1)
                canAllocate = 0;

        if (canAllocate) {
            for (int j = start; j < start + length; j++)
                disk[j] = 1;
            printf("File %d allocated blocks %d to %d.\n", i + 1, start, start + length - 1);
        } else {
            printf("File %d could not be allocated (blocks unavailable).\n", i + 1);
        }
    }

    printf("\nDisk block status:\n");
    for (int i = 0; i < totalBlocks; i++)
        printf("Block %d: %s\n", i, disk[i] ? "Allocated" : "Free");

    return 0;
}
