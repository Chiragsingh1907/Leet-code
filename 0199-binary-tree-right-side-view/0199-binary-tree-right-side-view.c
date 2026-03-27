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
void solve(struct TreeNode* root, int depth, int* res, int* returnSize) {
    if (root == NULL) return;

    // If this is the first node we encounter at this depth, add it to results
    if (depth == *returnSize) {
        res[(*returnSize)++] = root->val;
    }

    // Prioritize the right side to ensure the rightmost node is picked first
    solve(root->right, depth + 1, res, returnSize);
    solve(root->left, depth + 1, res, returnSize);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    // Constraints say max 100 nodes, so max depth is 100
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    
    solve(root, 0, res, returnSize);
    
    return res;
}