#include<stdio.h>

#define INF 9999

void floydWarshall(int graph[10][10], int n)
{
    int i, j, k;

    // Updating shortest distances
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Print shortest distance matrix
    printf("Shortest distance matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(graph[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, i, j;
    int graph[10][10];

    printf("Enter number of vertices:\n");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    printf("Use %d for no direct edge\n", INF);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, n);

    return 0;
}
