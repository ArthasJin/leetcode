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

// another solution
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
        sumToLeaf(root, 0);
        return res;
    }
private:
    int res;
    void sumToLeaf(TreeNode *root, int sum) {
        if (root) {
            if (!root->left && !root->right) {
                res += sum * 10 + root->val;
            }
            if (root->left) {
                sumToLeaf(root->left, sum * 10 + root->val);
            }
            if (root->right) {
                sumToLeaf(root->right, sum * 10 + root->val);
            }
        }
    }
};

