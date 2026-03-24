/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // Base case: if root is null or matches one of the target nodes
    if (root == NULL || root == p || root == q) {
        return root;
    }

    // Search in left and right subtrees
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both left and right returned something, root is the LCA
    if (left != NULL && right != NULL) {
        return root;
    }

    // Otherwise, return the one that is not NULL
    return (left != NULL) ? left : right;
}