#include <stdio.h>
#include <stdlib.h>

/**
 * Helper function to perform Depth First Search.
 * It marks all cities in the same province as visited.
 */
void dfs(int** isConnected, int* visited, int n, int currentCity) {
    for (int neighbor = 0; neighbor < n; neighbor++) {
        // If there is a connection and the neighbor hasn't been visited yet
        if (isConnected[currentCity][neighbor] == 1 && !visited[neighbor]) {
            visited[neighbor] = 1; // Mark as visited
            dfs(isConnected, visited, n, neighbor); // Recursive call
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int* visited = (int*)calloc(n, sizeof(int));
    int provinceCount = 0;

    for (int i = 0; i < n; i++) {
        // If city 'i' is not visited, it's the start of a new province
        if (!visited[i]) {
            provinceCount++;
            visited[i] = 1; // Mark the starting city
            dfs(isConnected, visited, n, i);
        }
    }

    free(visited);
    return provinceCount;
}