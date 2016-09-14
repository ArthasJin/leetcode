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
    void traversal(TreeNode *root, TreeNode* parent, int cur, int& result) {
        if (!root) {
            return;
        }
        if (parent && ((parent->val + 1) == root->val)) {
            cur++;
        } else {
            cur = 1;
        }
        result = max(cur, result);
        traversal(root->left, root, cur, result);
        traversal(root->right, root, cur, result);
    }
public:
    int longestConsecutive(TreeNode* root) {
        int result = 0;
        traversal(root, nullptr, 0, result);
        return result;
    }
};

