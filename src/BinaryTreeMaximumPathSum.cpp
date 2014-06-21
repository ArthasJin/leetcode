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
    int maxPathSum(TreeNode *root) {
        if (root) {
            maxSum = INT_MIN;
            pathSum(root);
        }
        return maxSum;
    }
private:
    int maxSum;
    int pathSum(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = pathSum(root->left);
        int right = pathSum(root->right);
        int sum = root->val;
        if (left > 0) {
            sum += left;
        }
        if (right > 0) {
            sum += right;
        }
        maxSum = max(maxSum, sum);
        if (left < 0 && right < 0) {
            return root->val;
        } else {
            return root->val + max(left, right);
        }
    }
};

