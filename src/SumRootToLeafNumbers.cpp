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
    int sumNumbers(TreeNode *root) {
        return traversal(root, 0);
    }
private:
    int traversal(TreeNode *root, int sum) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 10 * sum + root->val;
        }
        return traversal(root->left, sum * 10 + root->val) + traversal(root->right, sum * 10 + root->val);
    }
};

