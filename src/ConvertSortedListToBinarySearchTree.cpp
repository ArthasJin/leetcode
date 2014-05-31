/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        ListNode *p = head;
        while(p) {
            p = p->next;
            n++;
        }
        return buildBST(head, 1, n);
    }
private:
    TreeNode *buildBST(ListNode* &head, int start, int end) {
        if (start > end) {
            return NULL;
        }
        TreeNode *left = buildBST(head, start, start + (end - start) / 2 - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        TreeNode *right = buildBST(head, start + (end - start) / 2 + 1, end);
        root->left = left;
        root->right = right;
        return root;
    }
};

