#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int *neighbors;
    int size;
    int capacity;
} AdjList;

void add_edge(AdjList *adj, int u, int v) {
    if (adj[u].size == adj[u].capacity) {
        adj[u].capacity = adj[u].capacity == 0 ? 2 : adj[u].capacity * 2;
        adj[u].neighbors = realloc(adj[u].neighbors, adj[u].capacity * sizeof(int));
    }
    adj[u].neighbors[adj[u].size++] = v;
}

void dfs(int u, int p, int *timer, int *disc, int *low, AdjList *adj, int **res, int *resSize) {
    disc[u] = low[u] = ++(*timer);
    
    for (int i = 0; i < adj[u].size; i++) {
        int v = adj[u].neighbors[i];
        if (v == p) continue; // Don't go back to parent
        
        if (disc[v] == 0) { // If v is not visited
            dfs(v, u, timer, disc, low, adj, res, resSize);
            low[u] = MIN(low[u], low[v]);
            
            // Bridge condition
            if (low[v] > disc[u]) {
                res[*resSize] = (int *)malloc(2 * sizeof(int));
                res[*resSize][0] = u;
                res[*resSize][1] = v;
                (*resSize)++;
            }
        } else {
            // Update low value for back-edge
            low[u] = MIN(low[u], disc[v]);
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    AdjList *adj = calloc(n, sizeof(AdjList));
    for (int i = 0; i < connectionsSize; i++) {
        add_edge(adj, connections[i][0], connections[i][1]);
        add_edge(adj, connections[i][1], connections[i][0]);
    }

    int *disc = calloc(n, sizeof(int));
    int *low = calloc(n, sizeof(int));
    int timer = 0;
    
    int **res = malloc(connectionsSize * sizeof(int *));
    *returnSize = 0;

    dfs(0, -1, &timer, disc, low, adj, res, returnSize);

    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    // Clean up adjacency list
    for (int i = 0; i < n; i++) free(adj[i].neighbors);
    free(adj);
    free(disc);
    free(low);

    return res;
}