#include <stdbool.h>
#include <stdlib.h>

// Standard Adjacency List Node
struct Node {
    int val;
    struct Node* next;
};

bool hasCycle(int v, int* state, struct Node** adj) {
    if (state[v] == 1) return true;  // Found a back-edge (cycle)
    if (state[v] == 2) return false; // Already fully explored

    state[v] = 1; // Mark as "Visiting"

    struct Node* curr = adj[v];
    while (curr != NULL) {
        if (hasCycle(curr->val, state, adj)) return true;
        curr = curr->next;
    }

    state[v] = 2; // Mark as "Visited"
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // 1. Build Adjacency List
    struct Node** adj = (struct Node**)malloc(numCourses * sizeof(struct Node*));
    for (int i = 0; i < numCourses; i++) adj[i] = NULL;

    for (int i = 0; i < prerequisitesSize; i++) {
        int dest = prerequisites[i][0];
        int src = prerequisites[i][1];
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = dest;
        newNode->next = adj[src];
        adj[src] = newNode;
    }

    // 2. Initialize state array (0: unvisited, 1: visiting, 2: visited)
    int* state = (int*)calloc(numCourses, sizeof(int));

    // 3. Perform DFS for every node
    for (int i = 0; i < numCourses; i++) {
        if (state[i] == 0) {
            if (hasCycle(i, state, adj)) {
                // Cleanup (Optional for LC, but good practice)
                free(state);
                return false; 
            }
        }
    }

    free(state);
    return true;
}