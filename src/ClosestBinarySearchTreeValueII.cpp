/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void traverse(TreeNode* root, double target, stack<int>& s, bool reverse) {
        if (!root) {
            return;
        }
        traverse(reverse ? root->right : root->left, target, s, reverse);
        if ((reverse && root->val <= target) || (!reverse && root->val > target)) {
            return;
        }
        s.push(root->val);
        traverse(reverse ? root->left : root->right, target, s, reverse);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<int> s1, s2;
        traverse(root, target, s1, false);
        traverse(root, target, s2, true);
        vector<int> res;
        while (k-- > 0) {
            if (s1.empty()) {
                res.push_back(s2.top());
                s2.pop();
            } else if (s2.empty()) {
                res.push_back(s1.top());
                s1.pop();
            } else if (abs(s1.top() - target) < abs(s2.top() - target)) {
                res.push_back(s1.top());
                s1.pop();
            } else {
                res.push_back(s2.top());
                s2.pop();
            }
        }
        return res;
    }
};

