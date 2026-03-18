/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

#include <math.h>

int maxDepth(struct TreeNode* root) {
    // Base Case: If the tree is empty
    if (root == NULL) {
        return 0;
    }

    // Recursive calls for left and right subtrees
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    // Return the maximum of the two plus 1 for the current node
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}