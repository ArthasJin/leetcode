/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode *root) {
        if (!root) {
            return;
        }
        s.push(root);
        while (root->left) {
            s.push(root->left);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (s.empty()) {
            return -1;
        }
        TreeNode *node = s.top();
        s.pop();
        int result = node->val;
        if (node->right) {
            node = node->right;
            s.push(node);
            while (node->left) {
                s.push(node->left);
                node = node->left;
            }
        }
        return result;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

