/*
 * Experiment 33: Simulate the Optimal page replacement technique.
 * Compile: gcc 33_optimal_page_replacement.c -o exp33
 * Run:     ./exp33
 */
#include <stdio.h>

int predict(int pages[], int frame[], int frames, int n, int index) {
    int farthest = index, replaceIdx = -1;
    for (int i = 0; i < frames; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) { farthest = j; replaceIdx = i; }
                break;
            }
        }
        if (j == n) return i; /* not used again: replace this one */
    }
    return (replaceIdx == -1) ? 0 : replaceIdx;
}

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

    int faults = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++)
            if (frame[j] == pages[i]) { found = 1; break; }

        if (!found) {
            int emptyIdx = -1;
            for (int j = 0; j < frames; j++)
                if (frame[j] == -1) { emptyIdx = j; break; }

            if (emptyIdx != -1) {
                frame[emptyIdx] = pages[i];
            } else {
                int replaceIdx = predict(pages, frame, frames, n, i + 1);
                frame[replaceIdx] = pages[i];
            }
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
