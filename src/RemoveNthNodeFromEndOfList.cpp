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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head) {
            ListNode *cur = head, *start = head;
            ListNode *pre = NULL;
            while(start && n--) start = start->next;
            while(cur && start) {
                pre = cur;
                cur = cur->next;
                start = start->next;
            }
            if (pre) {
                pre->next = cur->next;
            } else {
                return head->next;
            }
        }
        return head;
    }
};

