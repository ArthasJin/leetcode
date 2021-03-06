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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p != NULL && q != NULL && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
        } else if (p == NULL && q == NULL) {
            return true;
        } else {
            return false;
        }
    }
};

