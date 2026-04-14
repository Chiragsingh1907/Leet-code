#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Standard Find operation with Path Compression
int find(int* parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

// Standard Union operation
void unite(int* parent, int rootU, int rootV) {
    parent[rootU] = rootV;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    // Nodes are labeled 1 to n. 
    // n is equal to edgesSize.
    int n = edgesSize;
    int* parent = (int*)malloc((n + 1) * sizeof(int));
    
    // Initialize each node as its own parent
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU == rootV) {
            // Cycle detected!
            result[0] = u;
            result[1] = v;
            // We don't break here if we want the "last" one, 
            // but since only ONE edge is added to a tree, 
            // the first cycle-completer we find IS the last redundant edge.
            free(parent);
            return result;
        } else {
            unite(parent, rootU, rootV);
        }
    }

    free(parent);
    return result;
}