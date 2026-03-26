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
int getHeight(struct TreeNode* root) {
    if (!root) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int height = getHeight(root);
    int** result = (int**)malloc(height * sizeof(int*));
    *returnColumnSizes = (int*)malloc(height * sizeof(int));
    *returnSize = height;

    struct TreeNode** queue = (struct TreeNode**)malloc(2001 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    bool leftToRight = true;
    int currentLevel = 0;

    while (head < tail) {
        int levelSize = tail - head;
        (*returnColumnSizes)[currentLevel] = levelSize;
        result[currentLevel] = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            
            // Calculate index: if right-to-left, fill the array from the end
            int index = leftToRight ? i : (levelSize - 1 - i);
            result[currentLevel][index] = node->val;

            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }

        leftToRight = !leftToRight; // Toggle direction
        currentLevel++;
    }

    free(queue);
    return result;
}