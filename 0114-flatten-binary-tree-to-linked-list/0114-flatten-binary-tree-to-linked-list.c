/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left != NULL) {
            // Find the rightmost node in the left subtree
            struct TreeNode* predecessor = curr->left;
            while (predecessor->right != NULL) {
                predecessor = predecessor->right;
            }

            // Connect the rightmost node of left subtree to current's right
            predecessor->right = curr->right;

            // Move left subtree to the right and nullify left
            curr->right = curr->left;
            curr->left = NULL;
        }
        // Move to the next node in the flattened chain
        curr = curr->right;
    }
}