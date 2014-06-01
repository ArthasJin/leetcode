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
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(-1);
        ListNode *pre = &dummy;
        pre->next = head;
        ListNode *cur = head;
        while(cur && cur->next) {
            ListNode *tmp = cur->next->next;
            pre->next = cur->next;
            cur->next->next = cur;
            pre = cur;
            cur->next = tmp;
            cur = cur->next;
        }
        return dummy.next;
    }
};

