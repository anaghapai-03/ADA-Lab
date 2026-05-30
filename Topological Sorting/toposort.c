#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], visited[MAX], stack[MAX];
int n, top = -1;

// DFS function
void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            dfs(i);
    }

    stack[++top] = v;
}

// Topological Sort
void topoSort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }

    printf("Topological Order:\n");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topoSort();
    return 0;
}
