#include <stdio.h>

#define V 4        // Number of vertices
#define INF 99999  // Representation of infinity

void printPath(int path[V][V], int u, int v) {          //  Function to print the shortest path between two vertices
    if (path[u][v] == -1) {
        printf("%d ", u);
        return;
    }
    printPath(path, u, path[u][v]);
    printf("%d ", v);
}

//   Function to print the solution
void printSolution(int dist[V][V], int path[V][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nPaths:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j && dist[i][j] != INF) {
                printf("Path from %d to %d: ", i, j);
                printPath(path, i, j);
                printf("\n");
            }
        }
    }
}
void Floyds(int graph[V][V]) {
    int dist[V][V], path[V][V];

    for (int i = 0; i < V; i++) {               //Initialization
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if (i == j || graph[i][j] == INF)
                path[i][j] = -1;
            else
                path[i][j] = i;
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    printSolution(dist, path);
}

int main() {
    int graph[V][V] = {                             //Example graph. Here, 'INF' means that there is no direct edge between the vertices/nodes
        {0,   5,  INF, 10},                             
        {INF, 0,   3, INF},
        {3, INF, 0,   1},
        {INF, 10, INF, 0}
    };

    Floyds(graph);
    return 0;
}
