#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    explicit TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode *mirrorTree(TreeNode *root) {
    if (!root) {
        return nullptr;
    }
    TreeNode *newRoot = new TreeNode(root->val);
    newRoot = mirrorTree(root->left);
    newRoot = mirrorTree(root->right);
    return newRoot;
}

