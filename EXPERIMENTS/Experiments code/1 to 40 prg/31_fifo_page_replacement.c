/*
 * Experiment 31: Simulate the FIFO page replacement technique.
 * Compile: gcc 31_fifo_page_replacement.c -o exp31
 * Run:     ./exp31
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

    int frame[frames];
    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    int faults = 0, front = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) { found = 1; break; }
        }
        if (!found) {
            frame[front] = pages[i];
            front = (front + 1) % frames;
            faults++;
        }
        printf("Page %d -> Frames: ", pages[i]);
        for (int j = 0; j < frames; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
    return 0;
}
