#include <stdio.h>
#include <stdbool.h>

void dfs(int** isConnected, int n, int* visited, int city) {
    // Mark the current city as visited
    visited[city] = 1;
    
    for (int neighbor = 0; neighbor < n; neighbor++) {
        // If there is a connection and the neighbor hasn't been visited yet
        if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
            dfs(isConnected, n, visited, neighbor);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int visited[200] = {0}; // Constraints say n <= 200
    int provinces = 0;
    
    for (int i = 0; i < n; i++) {
        // If city 'i' is not visited, it's part of a new province
        if (!visited[i]) {
            provinces++;
            dfs(isConnected, n, visited, i);
        }
    }
    
    return provinces;
}