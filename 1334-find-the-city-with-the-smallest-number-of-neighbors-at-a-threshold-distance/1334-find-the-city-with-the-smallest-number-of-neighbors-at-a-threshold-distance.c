#include <stdio.h>
#include <limits.h>

#define INF 1e7 // Large enough to exceed max path but prevent overflow

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int dist[n][n];

    // 1. Initialize distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    // 2. Fill in the edges (bidirectional)
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // 3. Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 4. Count reachable cities for each city and find the best candidate
    int minReachable = n; 
    int resultCity = -1;

    for (int i = 0; i < n; i++) {
        int reachableCount = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                reachableCount++;
            }
        }

        // Update if this city reaches fewer or equal cities (pick larger index on tie)
        if (reachableCount <= minReachable) {
            minReachable = reachableCount;
            resultCity = i;
        }
    }

    return resultCity;
}