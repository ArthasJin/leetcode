// inorder traverse
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
    void flatten(TreeNode *root) {
        traverse(root);
        for (int i = 1; i < path.size(); ++i) {
            path[i - 1]->left = NULL;
            path[i - 1]->right = path[i];
        }
    }
private:
    vector<TreeNode *> path;
    void traverse(TreeNode *root) {
        if (!root) {
            return;
        }
        path.push_back(root);
        traverse(root->left);
        traverse(root->right);
    }
};

// in-place
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
    void flatten(TreeNode *root) {
        while(root) {
            TreeNode *pre = root->left;
            if (pre) {
                while(pre->right) {
                    pre = pre->right;
                }
                pre->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};

