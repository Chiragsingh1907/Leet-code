#include <stdbool.h>
#include <stdlib.h>

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    // visited array initialized to false (0)
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    
    // Simple stack for DFS to store keys we find
    int* stack = (int*)malloc(roomsSize * sizeof(int));
    int top = -1;

    // Start with room 0
    visited[0] = true;
    stack[++top] = 0;
    
    int visitedCount = 1;

    while (top >= 0) {
        int currentRoom = stack[top--];

        // Look at all keys in the current room
        for (int i = 0; i < roomsColSize[currentRoom]; i++) {
            int key = rooms[currentRoom][i];
            
            // If we haven't visited the room this key opens
            if (!visited[key]) {
                visited[key] = true;
                stack[++top] = key;
                visitedCount++;
            }
        }
    }

    // Clean up memory
    free(visited);
    free(stack);

    // If we visited all rooms, return true
    return visitedCount == roomsSize;
}