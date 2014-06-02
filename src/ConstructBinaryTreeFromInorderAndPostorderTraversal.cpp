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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() > 0 && postorder.size() > 0) {
            return build(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
        }
        return NULL;
    }
private:
    TreeNode *build(vector<int> &inorder, int start, int end, vector<int> &postorder, int postEnd) {
        if (start > end) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int mid = 0;
        for (int i = start; i < end + 1; ++i) {
            if (postorder[postEnd] == inorder[i]) {
                mid = i;
                break;
            }
        }
        root->left = build(inorder, start, mid - 1, postorder, postEnd - end + mid - 1);
        root->right = build(inorder, mid + 1, end, postorder, postEnd - 1);
        return root;
    }
};

