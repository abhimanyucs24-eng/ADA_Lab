#include <stdio.h>
#include <stdlib.h>

#define V 4
#define E 5

struct Edge {
    int src, dest, weight;
};

int parent[V];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    int u_set = find(u);
    int v_set = find(v);
    parent[u_set] = v_set;
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskal(struct Edge edges[]) {
    for (int i = 0; i < V; i++)
        parent[i] = i;

    qsort(edges, E, sizeof(edges[0]), compare);

    printf("Edge   Weight\n");
    int cost = 0, count = 0;

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            printf("%d - %d    %d\n", u, v, edges[i].weight);
            cost += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    printf("Minimum Cost = %d\n", cost);
}

int main() {
    struct Edge edges[E] = {
        {0,1,2},
        {0,2,3},
        {2,3,5},
        {0,3,6},
        {1,2,8}
    };

    kruskal(edges);
    return 0;
}