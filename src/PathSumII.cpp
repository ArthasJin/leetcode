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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (root) {
            vector<int> path;
            pathSum(root, sum, path);
        }
        return res;
    }
private:
    vector<vector<int> > res;
    void pathSum(TreeNode *root, int sum, vector<int> &path) {
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val) {
            res.push_back(path);
            return;
        }
        if (root->left) {
            pathSum(root->left, sum - root->val, path);
            path.pop_back();
        }
        if (root->right) {
            pathSum(root->right, sum - root->val, path);
            path.pop_back();
        }
    }
};

