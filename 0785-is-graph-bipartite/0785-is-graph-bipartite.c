#include <stdbool.h>
#include <stdlib.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    // color array: -1 = uncolored, 0 = color A, 1 = color B
    int* color = (int*)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++) color[i] = -1;

    // Queue for BFS
    int* queue = (int*)malloc(graphSize * sizeof(int));

    for (int i = 0; i < graphSize; i++) {
        // If the node is already colored, skip it
        if (color[i] != -1) continue;

        // Start BFS for a new component
        int head = 0, tail = 0;
        queue[tail++] = i;
        color[i] = 0; // Start coloring with 0

        while (head < tail) {
            int u = queue[head++];

            for (int j = 0; j < graphColSize[u]; j++) {
                int v = graph[u][j];

                if (color[v] == -1) {
                    // Color neighbor with the opposite color
                    color[v] = 1 - color[u];
                    queue[tail++] = v;
                } else if (color[v] == color[u]) {
                    // Conflict found: same color adjacent nodes
                    free(color);
                    free(queue);
                    return false;
                }
            }
        }
    }

    free(color);
    free(queue);
    return true;
}