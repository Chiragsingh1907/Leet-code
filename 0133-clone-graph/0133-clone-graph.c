/**
 * Definition for a Node.
 * struct Node {
 * int val;
 * int numNeighbors;
 * struct Node** neighbors;
 * };
 */

// Global/Static array to act as a Hash Map (val -> new Node pointer)
struct Node* map[101];

struct Node* clone(struct Node* s) {
    if (s == NULL) return NULL;

    // If we have already cloned this node, return the reference to the clone
    if (map[s->val] != NULL) {
        return map[s->val];
    }

    // Create a new node (Deep Copy)
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = s->val;
    newNode->numNeighbors = s->numNeighbors;
    
    // Store it in our map immediately to handle cycles
    map[s->val] = newNode;

    // Allocate memory for the neighbors pointer array
    if (s->numNeighbors > 0) {
        newNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * s->numNeighbors);
        for (int i = 0; i < s->numNeighbors; i++) {
            // Recursively clone each neighbor
            newNode->neighbors[i] = clone(s->neighbors[i]);
        }
    } else {
        newNode->neighbors = NULL;
    }

    return newNode;
}

struct Node* cloneGraph(struct Node* s) {
    // Reset the map for every test case (important for LeetCode)
    for (int i = 0; i < 101; i++) {
        map[i] = NULL;
    }
    
    return clone(s);
}