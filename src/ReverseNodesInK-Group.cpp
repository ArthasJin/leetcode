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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head) {
            return NULL;
        }
        ListNode* p = new ListNode(-1);
        p->next = head;
        head = p;
        ListNode* q = p;
        while (true) {
            int i = 0;
            while (q && i < k) {
                q = q->next;
                i++;
            }
            if (!q) {
                return head->next;
            } else {
                while (p->next != q) {
                    ListNode* d = p->next;
                    ListNode* l = q->next;
                    p->next = p->next->next;
                    q->next = d;
                    d->next = l;
                }
                for(int j = 0; j < k; j++) {
                    p = p->next;
                }
                q = p;
            }
        }
        return head->next;
    }
};

