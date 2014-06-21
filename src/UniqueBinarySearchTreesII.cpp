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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> res;
        generate(1, n, res);
        return res;
    }
private:
    void generate(int start, int end, vector<TreeNode *> &path) {
        if (start > end) {
            path.push_back(NULL);
            return;
        }
        for (int i = start; i < end + 1; ++i) {
            vector<TreeNode *> left;
            generate(start, i - 1, left);
            vector<TreeNode *> right;
            generate(i + 1, end, right);
            for (int li = 0; li < left.size(); ++li) {
                for (int ri = 0; ri < right.size(); ++ri) {
                    TreeNode *node = new TreeNode(i);
                    node->left = left[li];
                    node->right = right[ri];
                    path.push_back(node);
                }
            }
        }
    }
};

