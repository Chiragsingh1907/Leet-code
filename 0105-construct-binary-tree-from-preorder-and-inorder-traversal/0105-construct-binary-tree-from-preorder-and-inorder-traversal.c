/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

// Helper function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* build(int* preorder, int* preIdx, int* inorder, int inStart, int inEnd) {
    // Base case: if the range is invalid, return NULL
    if (inStart > inEnd) {
        return NULL;
    }

    // The current root is the element at preorder[*preIdx]
    int rootVal = preorder[(*preIdx)++];
    struct TreeNode* root = createNode(rootVal);

    // Find the index of the root in the inorder array
    int inIdx = inStart;
    while (inIdx <= inEnd && inorder[inIdx] != rootVal) {
        inIdx++;
    }

    // Recursively build left and right subtrees
    // Elements to the left of inIdx in 'inorder' are in the left subtree
    root->left = build(preorder, preIdx, inorder, inStart, inIdx - 1);
    
    // Elements to the right of inIdx in 'inorder' are in the right subtree
    root->right = build(preorder, preIdx, inorder, inIdx + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIdx = 0;
    return build(preorder, &preIdx, inorder, 0, inorderSize - 1);
}