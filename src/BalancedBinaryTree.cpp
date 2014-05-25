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
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalanced(root, depth);
    }
private:
    bool isBalanced(TreeNode *root, int &depth) {
        if (!root) {
            return true;
        }
        int leftDepth = 0, rightDepth = 0;
        bool leftBalanced = isBalanced(root->left, leftDepth);
        bool rightBalanced = isBalanced(root->right, rightDepth);
        depth = leftDepth > rightDepth? leftDepth + 1 : rightDepth + 1;
        return leftBalanced && rightBalanced && abs(leftDepth - rightDepth) < 2;
    }
};

