#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for Adjacency List Node
typedef struct Node {
    int target;
    int weight;
    struct Node* next;
} Node;

// Structure for Heap Node
typedef struct {
    int node;
    int dist;
} HeapNode;

// Min-Heap structure for Priority Queue
typedef struct {
    HeapNode* data;
    int size;
} MinHeap;

// Heap helper functions
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, int node, int dist) {
    int i = heap->size++;
    heap->data[i] = (HeapNode){node, dist};
    while (i > 0 && heap->data[i].dist < heap->data[(i - 1) / 2].dist) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(MinHeap* heap) {
    HeapNode root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int i = 0;
    while (i * 2 + 1 < heap->size) {
        int child = i * 2 + 1;
        if (child + 1 < heap->size && heap->data[child + 1].dist < heap->data[child].dist) child++;
        if (heap->data[i].dist <= heap->data[child].dist) break;
        swap(&heap->data[i], &heap->data[child]);
        i = child;
    }
    return root;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    // 1. Build Adjacency List
    Node** adj = (Node**)calloc(n + 1, sizeof(Node*));
    for (int i = 0; i < timesSize; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->target = times[i][1];
        newNode->weight = times[i][2];
        newNode->next = adj[times[i][0]];
        adj[times[i][0]] = newNode;
    }

    // 2. Initialize Distances
    int* dists = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) dists[i] = INT_MAX;
    dists[k] = 0;

    // 3. Dijkstra using Min-Heap
    MinHeap heap;
    heap.data = (HeapNode*)malloc(timesSize * 10 * sizeof(HeapNode)); // Sufficient buffer
    heap.size = 0;
    push(&heap, k, 0);

    while (heap.size > 0) {
        HeapNode current = pop(&heap);
        int u = current.node;
        int d = current.dist;

        if (d > dists[u]) continue;

        Node* curr = adj[u];
        while (curr) {
            int v = curr->target;
            int w = curr->weight;
            if (dists[u] + w < dists[v]) {
                dists[v] = dists[u] + w;
                push(&heap, v, dists[v]);
            }
            curr = curr->next;
        }
    }

    // 4. Calculate Result
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dists[i] == INT_MAX) return -1; // Unreachable node
        if (dists[i] > maxTime) maxTime = dists[i];
    }

    // Cleanup (Free memory to be safe, though LeetCode doesn't strictly require it)
    free(dists);
    free(heap.data);
    for (int i = 1; i <= n; i++) {
        Node* curr = adj[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(adj);

    return maxTime;
}