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
private:
    unordered_map<TreeNode*, int> memo;
public:
    int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (memo.find(root) != memo.end()) {
            return memo[root];
        }
        int val = 0;
        if (root->left) {
            val += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            val += rob(root->right->left) + rob(root->right->right);
        }
        int res = max(val + root->val, rob(root->left) + rob(root->right));
        memo[root] = res;
        return res;
    }
};

