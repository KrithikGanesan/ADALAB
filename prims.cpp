#include <stdio.h>
#include <time.h>

#define INFINITY 999999

int n, c[20][20], visited[20];

void prim();

int extractMin(int key[], int mstSet[]) {
    int min = INFINITY, min_index;
    for (int v = 1; v <= n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[]) {
    int cost = 0;
    for (int i = 2; i <= n; i++) {
        printf("%d--->%d = %d\n", parent[i], i, c[i][parent[i]]);
        cost += c[i][parent[i]];
    }
    printf("Total cost of Spanning tree is %d\n", cost);
}

void prim() {
    int parent[20];
    int key[20];

    for (int i = 1; i <= n; i++) {
        key[i] = INFINITY;
        visited[i] = 0;
    }

    key[1] = 0;
    parent[1] = -1;

    clock_t start_time = clock();

    for (int count = 1; count <= n - 1; count++) {
        int u = extractMin(key, visited);
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (c[u][v] && !visited[v] && c[u][v] < key[v]) {
                parent[v] = u;
                key[v] = c[u][v];
            }
        }
    }

    clock_t end_time = clock();
double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("Execution time: %f seconds\n", execution_time);
 printMST(parent);
}

int main() {
    printf("Enter number of vertices \n");
    scanf("%d", &n);
    printf("Enter the cost matrix \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
        visited[i] = 0;
    }
    prim();

    return 0;
}
