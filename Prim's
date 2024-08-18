#include <stdio.h>

#define INF 999

int prim(int cost[10][10], int n, int source) {
    int visited[10] = {0}, minCost = 0;
    int i, j, u, v, min;

    visited[source] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        u = v = 0;

        // Find the minimum cost edge from a visited vertex to an unvisited vertex
        for (j = 1; j <= n; j++) {
            if (visited[j]) {
                for (int k = 1; k <= n; k++) {
                    if (!visited[k] && cost[j][k] < min) {
                        min = cost[j][k];
                        u = j;
                        v = k;
                    }
                }
            }
        }

        if (u != 0 && v != 0) {
            visited[v] = 1;
            minCost += min;
            printf("\n %d -> %d Cost = %d", u, v, min);
        }
    }

    return minCost;
}

int main() {
    int a[10][10], n, i, j, source;

    printf("\n Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\n Enter the cost matrix (use 0 for self-loops and 999 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n Enter the source vertex: ");
    scanf("%d", &source);

    int totalCost = prim(a, n, source);
    printf("\n\n Total cost of the MST: %d\n", totalCost);

    return 0;
}
