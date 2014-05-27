/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root) {
            int depth = 1;
            return minDepth(root, depth);
        }
        return 0;
    }
private:
    int minDepth(TreeNode *root, int &depth) {
        if (root && !root->left && !root->right) {
            return depth;
        }
        int d = depth + 1;
        int leftDepth = INT_MAX;
        int rightDepth = INT_MAX;
        if (root->left) {
            leftDepth = minDepth(root->left, d);
        }
        if (root->right) {
            rightDepth = minDepth(root->right, d);
        }
        return min(leftDepth, rightDepth);
    }
};

