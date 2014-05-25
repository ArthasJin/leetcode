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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return toBST(num, 0, num.size() - 1);
    }
private:
    TreeNode* toBST(vector<int> &num, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (end + start) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = toBST(num, start, mid - 1);
        node->right = toBST(num, mid + 1, end);
        return node;
    }
};

