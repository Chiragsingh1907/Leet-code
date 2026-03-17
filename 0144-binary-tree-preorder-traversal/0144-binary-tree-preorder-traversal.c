/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // Constraints say max 100 nodes
    *returnSize = 0;
    
    if (root == NULL) return result;

    // Manual Stack for iterative traversal
    struct TreeNode* stack[100];
    int top = -1;

    // Push the root to start
    stack[++top] = root;

    while (top >= 0) {
        // Pop the top node
        struct TreeNode* node = stack[top--];
        result[(*returnSize)++] = node->val;

        // Push Right first, then Left (so Left is processed first)
        if (node->right) {
            stack[++top] = node->right;
        }
        if (node->left) {
            stack[++top] = node->left;
        }
    }

    return result;
}