#include<stdio.h>
#include<string.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    int u_root = find(u);
    int v_root = find(v);
    parent[u_root] = v_root;
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[MAX];

    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    for (int i = 0; i < V; i++)
        parent[i] = i;

    qsort(edges, E, sizeof(edges[0]), compare);

    int count = 0, i = 0, cost = 0;

    printf("\nEdge \tWeight\n");

    while (count < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = find(next.src);
        int y = find(next.dest);

        if (x != y) {
            printf("%d - %d \t%d\n", next.src, next.dest, next.weight);
            cost += next.weight;
            unionSet(x, y);
            count++;
        }
    }

    printf("Total Cost = %d\n", cost);

    return 0;
}
