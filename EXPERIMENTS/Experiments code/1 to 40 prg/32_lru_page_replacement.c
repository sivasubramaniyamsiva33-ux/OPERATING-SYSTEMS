/*
 * Experiment 32: Simulate the Least Recently Used (LRU) page
 * replacement technique.
 * Compile: gcc 32_lru_page_replacement.c -o exp32
 * Run:     ./exp32
 */
#include <stdio.h>

int main() {
    int n, frames;

    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[frames], lastUsed[frames];
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        lastUsed[i] = -1;
    }

    int faults = 0;

    for (int i = 0; i < n; i++) {
        int found = 0, j;
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) { found = 1; break; }
        }
        if (found) {
            lastUsed[j] = i;
        } else {
            int replaceIdx = 0, minIdx = lastUsed[0];
            for (int k = 1; k < frames; k++) {
                if (frame[k] == -1) { replaceIdx = k; break; }
                if (lastUsed[k] < minIdx) { minIdx = lastUsed[k]; replaceIdx = k; }
            }
            frame[replaceIdx] = pages[i];
            lastUsed[replaceIdx] = i;
            faults++;
        }
        printf("Page %d -> Frames: ", pages[i]);
        for (int k = 0; k < frames; k++)
            printf("%d ", frame[k]);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
    return 0;
}
