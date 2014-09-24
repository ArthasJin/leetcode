#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *arrayToTree(vector<int> &array, int i) {
    if (i >= array.size()) {
        return NULL;
    }
    TreeNode *root = new TreeNode(array[i]);
    root->left = arrayToTree(array, 2 * i + 1);
    root->right = arrayToTree(array, 2 * i + 2);
    return root;
}

