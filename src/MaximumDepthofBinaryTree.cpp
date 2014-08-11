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
    int maxDepth(TreeNode *root) {
        if (root) {
            if (root->left && root->right) {
                return 1 + max(maxDepth(root->left), maxDepth(root->right));
            } else if (root->left && !root->right) {
                return 1 + maxDepth(root->left);
            } else if (!root->left && root->right) {
                return 1 + maxDepth(root->right);
            } else {
                return 1;
            }
        }
        return 0;
    }
};

// more elegant solution
class Solution {
public:
    int maxDepth(TreeNode *root) {
        return depth(root);
    }
private:
    int depth(TreeNode *root) {
        if (root) {
            return 1 + max(depth(root->left), depth(root->right));
        }
        return 0;
    }
};

