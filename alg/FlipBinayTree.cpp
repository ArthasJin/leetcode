#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode * FlipTree (TreeNode *root) {
    if (!root) {
        return NULL;
    }
    // Working base condition
    if (!root->left && !root->right) {
        return root;
    }
    TreeNode *newRoot = FlipTree(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = NULL;
    root->right = NULL;
    return newRoot;
}

