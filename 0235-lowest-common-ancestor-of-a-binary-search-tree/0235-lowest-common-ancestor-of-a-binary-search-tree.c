/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        // If both nodes are in the left subtree
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        // If both nodes are in the right subtree
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        // We found the split point (one left, one right) or one of the nodes itself
        else {
            return root;
        }
    }
    return NULL;
}