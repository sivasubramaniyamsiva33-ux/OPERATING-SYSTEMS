/*
 * Experiment 35: Simulate the indexed file allocation strategy,
 * where an index block holds pointers to each block of the file.
 * Compile: gcc 35_indexed_file_allocation.c -o exp35
 * Run:     ./exp35
 */
#include <stdio.h>

#define MAX_FILES 10
#define MAX_BLOCKS 20

int main() {
    int n, totalBlocks;
    int indexBlock[MAX_FILES][MAX_BLOCKS];
    int blockCount[MAX_FILES];

    printf("Enter total disk blocks: ");
    scanf("%d", &totalBlocks);

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter number of blocks for file %d: ", i + 1);
        scanf("%d", &blockCount[i]);
        printf("Enter %d block numbers for file %d: ", blockCount[i], i + 1);
        for (int j = 0; j < blockCount[i]; j++)
            scanf("%d", &indexBlock[i][j]);
    }

    printf("\nIndexed File Allocation Table:\n");
    for (int i = 0; i < n; i++) {
        printf("File %d -> Index Block contains: ", i + 1);
        for (int j = 0; j < blockCount[i]; j++)
            printf("%d ", indexBlock[i][j]);
        printf("\n");
    }

    return 0;
}
