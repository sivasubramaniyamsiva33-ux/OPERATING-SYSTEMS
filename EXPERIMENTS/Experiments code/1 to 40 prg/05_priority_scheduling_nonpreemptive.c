/*
 * Experiment 5: Scheduling program that selects the waiting process
 * with the highest priority to execute next (non-preemptive).
 * Lower numeric value = higher priority.
 * Compile: gcc 05_priority_scheduling_nonpreemptive.c -o exp5
 * Run:     ./exp5
 */
#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], pr[n], p[n];

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter burst time and priority for P%d: ", p[i]);
        scanf("%d %d", &bt[i], &pr[i]);
    }

    /* sort by priority (lower value = higher priority) */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pr[j] > pr[j + 1]) {
                temp = pr[j]; pr[j] = pr[j + 1]; pr[j + 1] = temp;
                temp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp;
                temp = p[j];  p[j]  = p[j + 1];  p[j + 1]  = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
    return 0;
}
