#include <stdio.h>
#define MAX 10

void topologicalSort(int V[MAX][MAX], int n) {
    int indegree[MAX];
    int visited[MAX];
    int TP[MAX];
    int tp_count = 0; //used to ensure the graph in cyclic or not                                                                                                                                                                                                                                                                                                                            

    // Step 1: Compute indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (V[j][i] == 1)
                indegree[i]++;
        }
    }

    // Step 2: Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Step 3: Main loop
    while (1) {
        int w = -1;

        // Find vertex with indegree 0 and not visited
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && indegree[i] == 0) {
                w = i;
                break;
            }
        }

        // No such vertex found
        if (w == -1)
            break;

        // Add to topological order
        TP[tp_count++] = w;
        visited[w] = 1;

        // Decrease indegree of adjacent vertices
        for (int i = 0; i < n; i++) {
            if (V[w][i] == 1)
                indegree[i]--;
        }
    }

    // Step 4: Check for cycle
    if (tp_count < n) {
        printf("No Topological Sequence (cycle detected)\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < tp_count; i++)
            printf("%d ", TP[i]);
        printf("\n");
    }
}

int main() {
    int n = 6;

    int V[MAX][MAX] = {
        {0,0 ,1,0,0,0},
        {1,0,0,1,0,0},
        {0,0,0,1,1,0},
        {0,0,0,0,0,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0}
    };

    topologicalSort(V, n);

    return 0;
}