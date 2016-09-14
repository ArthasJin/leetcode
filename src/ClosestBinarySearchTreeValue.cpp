/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (root) {
            int result = 0;
            if (target > root->val) {
                result = closestValue(root->right, target);
            } else if (target < root->val) {
                result = closestValue(root->left, target);
            } else {
                return root->val;
            }
            if (result == -1) {
                return root->val;
            }
            return abs(result - target) > abs(root->val - target) ? root->val : result;
        }
        return -1;
    }
};

