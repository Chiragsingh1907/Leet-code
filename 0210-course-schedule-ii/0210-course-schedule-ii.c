#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct Node {
    int val;
    struct Node* next;
} Node;

bool hasCycle(int u, Node** adj, int* state, int* stack, int* top) {
    state[u] = 1; // Mark as Visiting

    Node* curr = adj[u];
    while (curr) {
        int v = curr->val;
        if (state[v] == 1) return true; // Cycle detected
        if (state[v] == 0) {
            if (hasCycle(v, adj, state, stack, top)) return true;
        }
        curr = curr->next;
    }

    state[u] = 2; // Mark as Visited
    stack[(*top)++] = u; // Add to ordering
    return false;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    // 1. Build Adjacency List
    Node** adj = (Node**)calloc(numCourses, sizeof(Node*));
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = course;
        newNode->next = adj[pre]; // Edge: pre -> course
        adj[pre] = newNode;
    }

    int* state = (int*)calloc(numCourses, sizeof(int));
    int* result = (int*)malloc(numCourses * sizeof(int));
    int top = 0;

    // 2. Perform DFS for each node
    for (int i = 0; i < numCourses; i++) {
        if (state[i] == 0) {
            if (hasCycle(i, adj, state, result, &top)) {
                // Cycle found, return empty array
                *returnSize = 0;
                // Free memory (omitted for brevity, but good practice)
                return NULL;
            }
        }
    }

    // 3. Reverse the result (DFS gives post-order, we need reverse for topo)
    // Note: Because I pushed 'u' AFTER neighbors, my stack already contains
    // the finish order. To get topo, we reverse it. 
    // Actually, in the code above, the nodes added last are at the end.
    // Let's swap to get the correct order.
    for (int i = 0; i < top / 2; i++) {
        int temp = result[i];
        result[i] = result[top - 1 - i];
        result[top - 1 - i] = temp;
    }

    *returnSize = numCourses;
    return result;
}