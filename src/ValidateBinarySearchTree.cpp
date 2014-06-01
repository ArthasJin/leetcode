/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// in order traverse
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        traverse(root);
        for (int i = 1; i < res.size(); ++i) {
            if (res[i] <= res[i - 1]) {
                return false;
            }
        }
        return true;
    }
private:
    vector<int> res;
    void traverse(TreeNode *root) {
        if (!root) {
            return;
        }
        traverse(root->left);
        res.push_back(root->val);
        traverse(root->right);
    }
};

// dfs
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
    bool isValidBST(TreeNode *root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
private:
    bool isValid(TreeNode *root, int low, int high) {
        if (!root) {
            return true;
        }
        return root->val > low && root->val < high && isValid(root->left, low, root->val) && isValid(root->right, root->val, high);
    }
};

