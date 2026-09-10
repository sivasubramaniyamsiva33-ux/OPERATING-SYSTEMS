/*
 * Experiment 36: Simulate linked allocation, where each file is a
 * linked list of disk blocks scattered anywhere on the disk.
 * Compile: gcc 36_linked_file_allocation.c -o exp36
 * Run:     ./exp36
 */
#include <stdio.h>

#define MAX_BLOCKS 20

struct Block {
    int occupied;
    int next;
};

int main() {
    struct Block disk[MAX_BLOCKS];
    int totalBlocks, n;

    for (int i = 0; i < MAX_BLOCKS; i++) {
        disk[i].occupied = 0;
        disk[i].next = -1;
    }

    printf("Enter total disk blocks: ");
    scanf("%d", &totalBlocks);

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int numBlocks, start;
        printf("Enter number of blocks for file %d: ", i + 1);
        scanf("%d", &numBlocks);

        int prev = -1, first = -1;
        printf("Enter %d block numbers (in order) for file %d: ", numBlocks, i + 1);
        for (int j = 0; j < numBlocks; j++) {
            scanf("%d", &start);
            disk[start].occupied = 1;
            if (prev != -1)
                disk[prev].next = start;
            else
                first = start;
            prev = start;
        }
        disk[prev].next = -1;

        printf("File %d starts at block %d, chain: ", i + 1, first);
        int curr = first;
        while (curr != -1) {
            printf("%d -> ", curr);
            curr = disk[curr].next;
        }
        printf("NULL\n");
    }

    return 0;
}
