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
        if (!head || !head->next) {
            return head;
        }
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        head = pre;
        ListNode *p = head;
        while(p->next) {
            ListNode *p2 = p->next;
            while (p2->next && (p2->val == p2->next->val)) {
                p2 = p2->next;
            }
            if (p2 != p->next) {
                p->next = p2->next;
            } else {
                p = p->next;
            }
        }
        return head->next;
    }
};

