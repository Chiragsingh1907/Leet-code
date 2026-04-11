#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e9

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    // dist array keeps track of the minimum cost to reach each city
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // We can take at most k + 1 flights
    for (int i = 0; i <= k; i++) {
        // Create a copy of the current distances to ensure we only 
        // use results from the previous 'layer' of flights.
        int* temp = (int*)malloc(n * sizeof(int));
        memcpy(temp, dist, n * sizeof(int));

        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int price = flights[j][2];

            // If the starting city of the flight was reachable in the previous iteration
            if (dist[u] != INF) {
                if (dist[u] + price < temp[v]) {
                    temp[v] = dist[u] + price;
                }
            }
        }
        // Free old dist and point to the updated temp array
        free(dist);
        dist = temp;
    }

    int result = dist[dst];
    free(dist);

    return (result == INF) ? -1 : result;
}