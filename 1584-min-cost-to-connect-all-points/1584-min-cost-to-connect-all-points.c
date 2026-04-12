#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int totalCost = 0;
    int edgesConnected = 0;
    
    // visited[i] tracks if point i is already in the MST
    int* visited = (int*)calloc(n, sizeof(int));
    // minDist[i] tracks the shortest distance to point i from the current MST
    int* minDist = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
    }
    
    // Start with the first point
    minDist[0] = 0;
    
    while (edgesConnected < n) {
        int currMin = INT_MAX;
        int currNode = -1;
        
        // Find the non-visited node with the minimum distance to the MST
        for (int i = 0; i < n; i++) {
            if (!visited[i] && minDist[i] < currMin) {
                currMin = minDist[i];
                currNode = i;
            }
        }
        
        // Add current node to MST
        visited[currNode] = 1;
        totalCost += currMin;
        edgesConnected++;
        
        // Update distances to neighboring nodes
        for (int nextNode = 0; nextNode < n; nextNode++) {
            if (!visited[nextNode]) {
                int dist = abs(points[currNode][0] - points[nextNode][0]) + 
                           abs(points[currNode][1] - points[nextNode][1]);
                
                if (dist < minDist[nextNode]) {
                    minDist[nextNode] = dist;
                }
            }
        }
    }
    
    free(visited);
    free(minDist);
    
    return totalCost;
}