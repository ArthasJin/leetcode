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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() > 0 && inorder.size() > 0) {
            return build(preorder, 0, inorder, 0, inorder.size() - 1);
        }
        return NULL;
    }
private:
    TreeNode *build(vector<int> &preorder, int preStart, vector<int> &inorder, int start, int end) {
        if (start > end) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int mid = 0;
        for (int i = start; i < end + 1; ++i) {
            if (preorder[preStart] == inorder[i]) {
                mid = i;
                break;
            }
        }
        root->left = build(preorder, preStart + 1, inorder, start, mid - 1);
        root->right = build(preorder, preStart + mid + 1 - start, inorder, mid + 1, end);
        return root;
    }
};

