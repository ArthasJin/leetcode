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
    vector<int> preorderTraversal(TreeNode *root) {
        traversal(root);
        return res;
    }
private:
    vector<int> res;
    void traversal(TreeNode *root) {
        if (root) {
            res.push_back(root->val);
            traversal(root->left);
            traversal(root->right);
        }
    }
};

