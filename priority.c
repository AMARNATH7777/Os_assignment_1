#include <stdio.h>
#include <string.h>
struct Process {
    char pid[10];
    int at, bt, pr;
    int ct, tat, wt;
    int completed;
};
int main() {
    int n, i, completed = 0, current_time = 0;
    float total_wt = 0, total_tat = 0;
    scanf("%d", &n);
    struct Process p[n];
    for(i = 0; i < n; i++) {
        scanf("%s %d %d %d", p[i].pid, &p[i].at, &p[i].bt, &p[i].pr);
        p[i].completed = 0;
    }
    while(completed < n) {
        int idx = -1;
        int max_pr = -1;
        for(i = 0; i < n; i++) {
            if(p[i].at <= current_time && p[i].completed == 0) {
                if(p[i].pr > max_pr) {
                    max_pr = p[i].pr;
                    idx = i;
                }
            }
        }
        if(idx == -1) {
            current_time++;
        } else {
            current_time += p[idx].bt;
            p[idx].ct = current_time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            total_wt += p[idx].wt;
            total_tat += p[idx].tat;

            p[idx].completed = 1;
            completed++;
        }
    }
    printf("Waiting Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].wt);
    }
    printf("Turnaround Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].tat);
    }
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    return 0;
}
