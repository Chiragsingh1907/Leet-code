/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* helper(int* inorder, int inStart, int inEnd, int* postorder, int* postIdx) {
    if (inStart > inEnd) return NULL;

    // Root is the last element of current postorder range
    int rootVal = postorder[(*postIdx)--];
    struct TreeNode* root = createNode(rootVal);

    // Find the index of root in inorder array
    int pivot = inStart;
    while (inorder[pivot] != rootVal) {
        pivot++;
    }

    // Build Right Subtree then Left Subtree
    root->right = helper(inorder, pivot + 1, inEnd, postorder, postIdx);
    root->left = helper(inorder, inStart, pivot - 1, postorder, postIdx);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIdx = postorderSize - 1;
    return helper(inorder, 0, inorderSize - 1, postorder, &postIdx);
}