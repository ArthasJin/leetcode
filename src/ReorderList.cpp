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
    void reorderList(ListNode *head) {
        if (!head) {
            return;
        }
        if (head->next == NULL) {
            return;
        }
        ListNode *p = head;
        ListNode *q = head;

        //find the midddle pointer
        while (q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        //now p is middle pointer
        //reverse p->next to end
        q = p->next;
        while (q->next) {
            ListNode* tmp = p->next;
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = tmp;
        }
        //reorder
        q = head;
        while (p != q && p->next) {
            ListNode *tmp = q->next;
            q->next = p->next;
            p->next = p->next->next;
            q->next->next = tmp;
            q = q->next->next;
        }
        return;
    }
};

