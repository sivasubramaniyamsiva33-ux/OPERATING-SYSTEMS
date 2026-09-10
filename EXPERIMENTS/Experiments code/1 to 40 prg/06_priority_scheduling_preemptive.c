/*
 * Experiment 6: Preemptive priority scheduling algorithm.
 * Lower numeric value = higher priority.
 * Compile: gcc 06_priority_scheduling_preemptive.c -o exp6
 * Run:     ./exp6
 */
#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], art[n], pr[n], rem_bt[n];
    int wt[n], tat[n], is_done[n];
    int completed = 0, t = 0, minm, id;

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time, burst time and priority for P%d: ", i + 1);
        scanf("%d %d %d", &art[i], &bt[i], &pr[i]);
        rem_bt[i] = bt[i];
        is_done[i] = 0;
    }

    while (completed != n) {
        minm = INT_MAX;
        id = -1;
        for (int i = 0; i < n; i++) {
            if (art[i] <= t && !is_done[i] && rem_bt[i] > 0 && pr[i] < minm) {
                minm = pr[i];
                id = i;
            }
        }
        if (id == -1) {
            t++;
            continue;
        }
        rem_bt[id]--;
        t++;
        if (rem_bt[id] == 0) {
            completed++;
            is_done[id] = 1;
            tat[id] = t - art[id];
            wt[id] = tat[id] - bt[id];
        }
    }

    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tBurst\tArrival\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", i + 1, bt[i], art[i], pr[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
    return 0;
}
