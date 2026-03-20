int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root) return 0;
    
    int sum = 0;
    
    // Check if the left child exists and is a leaf
    if (root->left && !root->left->left && !root->left->right) {
        sum += root->left->val;
    }
    
    // Continue recursion for both sides
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}