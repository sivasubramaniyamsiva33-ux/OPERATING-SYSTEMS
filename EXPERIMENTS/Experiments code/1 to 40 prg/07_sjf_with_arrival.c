/*
 * Experiment 7: Non-preemptive Shortest Job First (SJF) algorithm,
 * accounting for different process arrival times.
 * Compile: gcc 07_sjf_with_arrival.c -o exp7
 * Run:     ./exp7
 */
#include <stdio.h>

struct Process {
    int pid, bt, art, wt, tat, completed;
};

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time and burst time for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].art, &p[i].bt);
        p[i].completed = 0;
    }

    int completed = 0, t = 0;
    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");

    while (completed != n) {
        int idx = -1, min_bt = 999999;
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].art <= t && p[i].bt < min_bt) {
                min_bt = p[i].bt;
                idx = i;
            }
        }
        if (idx == -1) {
            t++;
            continue;
        }
        t += p[idx].bt;
        p[idx].tat = t - p[idx].art;
        p[idx].wt = p[idx].tat - p[idx].bt;
        p[idx].completed = 1;
        completed++;
        total_wt += p[idx].wt;
        total_tat += p[idx].tat;
        printf("P%d\t%d\t%d\t%d\t%d\n", p[idx].pid, p[idx].art, p[idx].bt, p[idx].wt, p[idx].tat);
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
    return 0;
}
