#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // Create the new node
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    
    // If the tree is empty, the new node becomes the root
    if (root == NULL) {
        return newNode;
    }
    
    struct TreeNode* curr = root;
    
    // Traverse the tree to find the correct insertion point
    while (1) {
        if (val < curr->val) {
            // Go left
            if (curr->left == NULL) {
                curr->left = newNode;
                break;
            }
            curr = curr->left;
        } else {
            // Go right
            if (curr->right == NULL) {
                curr->right = newNode;
                break;
            }
            curr = curr->right;
        }
    }
    
    return root;
}