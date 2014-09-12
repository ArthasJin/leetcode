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

// iterative
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
        TreeNode *prev = NULL;
        stack<TreeNode *> stk;
        vector<int> res;
        if (root) {
            stk.push(root);
            while (!stk.empty()) {
                TreeNode *cur = stk.top();
                if (!prev || prev->left == cur || prev->right == cur) {
                    if (cur->left) {
                        stk.push(cur->left);
                    } else if (cur->right) {
                        stk.push(cur->right);
                    } else {
                        res.push_back(cur->val);
                        stk.pop();
                    }
                } else if (cur->left == prev) {
                    if (cur->right) {
                        stk.push(cur->right);
                    } else {
                        res.push_back(cur->val);
                        stk.pop();
                    }
                } else if (cur->right == prev) {
                    res.push_back(cur->val);
                    stk.pop();
                }
                prev = cur;
            }
        }
        return res;
    }
};

