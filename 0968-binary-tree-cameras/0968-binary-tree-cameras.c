/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* node, int* cameras) {
    if (node == NULL) return 2;

    int left = dfs(node->left, cameras);
    int right = dfs(node->right, cameras);

    if (left == 0 || right == 0) {
        (*cameras)++;
        return 1;
    }

    if (left == 1 || right == 1) {
        return 2;
    }

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    int cameras = 0;
    if (dfs(root, &cameras) == 0) {
        cameras++;
    }
    return cameras;
}