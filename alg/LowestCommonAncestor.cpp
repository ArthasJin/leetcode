#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *getLCA(TreeNode *root, TreeNode *node1, TreeNode *node2) {
    if (!root || !node1 || !node2) {
        return NULL;
    }
    if (root == node1 || root == node2) {
        return root;
    }
    TreeNode *left = getLCA(root->left, node1, node2);
    TreeNode *right = getLCA(root->right, node1, node2);
    if (!left) {
        return right;
    } else if (!right) {
        return left;
    } else {
        return root;
    }
}

