/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        if (head) {
            dummy.next = head;
            ListNode *cur = dummy.next;
            while(cur) {
                ListNode *p = cur->next;
                while(p && p->val == cur->val) {
                    p = p->next;
                }
                cur->next = p;
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};

