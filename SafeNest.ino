#include <stdio.h>
#include<stdlib.h
void calculate(int n, int bt[], int wt[], int tat[]) {
    wt[0] = 0; 
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

     for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}


int main() {
    int n, temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], wt[n], tat[n];

    printf("Enter Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

     for (int i = 0; i < n - 1; i++) {
 for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    calculate(n, bt, wt, tat);

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}

