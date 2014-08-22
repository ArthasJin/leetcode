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
    int minDepth(TreeNode *root) {
        if (root) {
            int depth = 1;
            return minDepth(root, depth);
        }
        return 0;
    }
private:
    int minDepth(TreeNode *root, int &depth) {
        if (root && !root->left && !root->right) {
            return depth;
        }
        int d = depth + 1;
        int leftDepth = INT_MAX;
        int rightDepth = INT_MAX;
        if (root->left) {
            leftDepth = minDepth(root->left, d);
        }
        if (root->right) {
            rightDepth = minDepth(root->right, d);
        }
        return min(leftDepth, rightDepth);
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
    int minDepth(TreeNode *root) {
        if (root) {
            depth = INT_MAX;
            minDepth(root, 1);
            return depth;
        }
        return 0;
    }
private:
    int depth;
    void minDepth(TreeNode *root, int cur) {
        if (root) {
            if (!root->left && !root->right) {
                depth = min(depth, cur);
            }
            if (root->left) {
                minDepth(root->left, cur + 1);
            }
            if (root->right) {
                minDepth(root->right, cur + 1);
            }
        }
    }
};

// more elegant soltuion
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
    int minDepth(TreeNode *root) {
        if (root) {
            if (!root->left && !root->right) {
                return 1;
            } else if (root->left && !root->right) {
                return 1 + minDepth(root->left);
            } else if (!root->left && root->right) {
                return 1 + minDepth(root->right);
            } else {
                return 1 + min(minDepth(root->left), minDepth(root->right));
            }
        }
        return 0;
    }
};

