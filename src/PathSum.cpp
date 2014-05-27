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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root) {
            return hasPath(root, sum);
        }
        return false;
    }
private:
    bool hasPath(TreeNode *root, int sum) {
        if (root) {
            sum -= root->val;
            if (!root->left && !root->right && sum == 0) {
                return true;
            } else if (!root->left && !root->right && sum != 0) {
                return false;
            }
            return hasPath(root->left, sum) || hasPath(root->right, sum);
        }
        return false;
    }
};

