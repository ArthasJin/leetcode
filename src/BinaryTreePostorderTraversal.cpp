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
    vector<int> postorderTraversal(TreeNode *root) {
        traversal(root);
        return res;
    }
private:
    vector<int> res;
    void traversal(TreeNode *root) {
        if (root) {
            traversal(root->left);
            traversal(root->right);
            res.push_back(root->val);
        }
    }
};

