#include <stddef.h> 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Traverse down the tree until we hit a NULL leaf or find the target value
    while (root != NULL && root->val != val) {
        if (val < root->val) {
            // Target is smaller, so it must be in the left subtree
            root = root->left;
        } else {
            // Target is larger, so it must be in the right subtree
            root = root->right;
        }
    }
    
    // If found, root points to the node. If not, root will be NULL.
    return root; 
}