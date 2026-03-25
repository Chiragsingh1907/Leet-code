/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    // Allocate memory for the result (max 2000 nodes, so max 2000 levels)
    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    // Queue for BFS
    struct TreeNode* queue[2000];
    int head = 0, tail = 0;

    // Push root
    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head; // Number of nodes at current level
        (*returnColumnSizes)[*returnSize] = levelSize;
        
        // Allocate space for the current level's values
        int* currentLevel = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            currentLevel[i] = node->val;

            if (node->left)  queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }

        result[*returnSize] = currentLevel;
        (*returnSize)++;
    }

    return result;
}