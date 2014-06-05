// O(n) space
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
    void recoverTree(TreeNode *root) {
        if (root) {
            traverse(root);
            sort(value.begin(), value.end());
            for (int i = 0; i < path.size(); ++i) {
                path[i]->val = value[i];
            }
        }
    }
private:
    vector<TreeNode *> path;
    vector<int> value;
    void traverse(TreeNode *root) {
        if (!root) {
            return;
        }
        traverse(root->left);
        path.push_back(root);
        value.push_back(root->val);
        traverse(root->right);
    }
};

// O(1) space
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
    void recoverTree(TreeNode *root) {
        if (root) {
            first = second = pre = NULL;
            traverse(root);
            swap(first->val, second->val);
        }
    }
private:
    TreeNode *first;
    TreeNode *second;
    TreeNode *pre;
    void traverse(TreeNode *root) {
        if (root) {
            traverse(root->left);
            if (pre && pre->val > root->val) {
                if (!first) {
                    first = pre;
                }
                second = root;
            }
            pre = root;
            traverse(root->right);
        }
    }
};

