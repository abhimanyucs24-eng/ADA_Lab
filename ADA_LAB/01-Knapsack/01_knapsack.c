#include <stdio.h>

int max(int a, int b) {             // Function to find max of two numbers
    return (a > b) ? a : b;
}

/*   0/1 Knapsack function   */
int knapsack(int W, int wt[], int val[], int n) {
    int V[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {              // Here, the table is built using bottom-up approach
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0)           // Base case
                V[i][w] = 0;

            else if (wt[i - 1] <= w)
                V[i][w] = max(val[i - 1] + V[i - 1][w - wt[i - 1]],V[i - 1][w]);

            else
                V[i][w] = V[i - 1][w];
        }
    }

    return V[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;

    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value = %d\n", knapsack(W, wt, val, n));

    return 0;
}