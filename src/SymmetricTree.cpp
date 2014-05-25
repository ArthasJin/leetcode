/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root) {
            return isSymmetric(root->left, root->right);
        }
        return true;
    }
private:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if ((left != NULL && right == NULL) || (left == NULL && right != NULL)) {
            return false;
        }
        if (left && right && (left->val != right->val)) {
            return false;
        } else if (left && right && (left->val == right->val)) {
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }
        return true;
    }
};

// BFS
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
    bool isSymmetric(TreeNode *root) {
        if (root) {
            return traversal(root);
        }
        return true;
    }
private:
    bool traversal(TreeNode *root) {
        queue<TreeNode *> q1, q2;
        q1.push(root);
        while(!q1.empty()) {
            vector<TreeNode *> level;
            while(!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                level.push_back(node);
                if (node) {
                    q2.push(node->left);
                    q2.push(node->right);
                }
            }
            swap(q1, q2);
            if (!isSymmetric(level)) {
                return false;
            }
        }
        return true;
    }
    bool isSymmetric(vector<TreeNode *> &level) {
        int start = 0, end = level.size() - 1;
        while(start < end) {
            if (level[start] && !level[end] || !level[start] && level[end]) {
                return false;
            }
            if (level[start] && level[end] && (level[start]->val != level[end]->val)) {
                return false;
            }
            start++, end--;
        }
        return true;
    }
};

