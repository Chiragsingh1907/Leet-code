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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // Constraints say max 100 nodes
    *returnSize = 0;
    
    if (root == NULL) return result;

    // Explicit Stack
    struct TreeNode* stack[100];
    int top = -1;
    
    struct TreeNode* curr = root;

    while (curr != NULL || top != -1) {
        // 1. Reach the leftmost node of the current subtree
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        // 2. Current must be NULL at this point, so pop from stack
        curr = stack[top--];
        result[(*returnSize)++] = curr->val;

        // 3. We have visited the node and its left subtree. 
        // Now, it's the right subtree's turn.
        curr = curr->right;
    }

    return result;
}