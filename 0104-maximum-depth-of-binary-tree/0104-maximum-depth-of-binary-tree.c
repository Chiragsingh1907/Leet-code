/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    // Base case: If the node is NULL, depth is 0
    if (root == NULL) {
        return 0;
    }

    // Recursively find the depth of left and right subtrees
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // Return the maximum of the two subtrees + 1 for the current node
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}