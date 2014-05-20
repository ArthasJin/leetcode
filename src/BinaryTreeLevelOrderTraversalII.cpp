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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        if (root) {
            traversal(root);
        }
        reverse(res.begin(), res.end());
        return res;
    }
private:
    vector<vector<int> > res;
    void traversal(TreeNode *root) {
        queue<TreeNode *> q1, q2;
        q1.push(root);
        while(!q1.empty()) {
            vector<int> level;
            while(!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                level.push_back(node->val);
                if (node->left) {
                    q2.push(node->left);
                }
                if (node->right) {
                    q2.push(node->right);
                }
            }
            swap(q1, q2);
            res.push_back(level);
        }
    }
};

