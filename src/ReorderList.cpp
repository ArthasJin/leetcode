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

// more elegant solution
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
        ListNode *l1 = head, *cur = head;
        ListNode *l2 = reverse(findMiddle(head));
        bool reversed = false;
        while(l1 || l2) {
            if (!reversed) {
                l1 = l1 ? l1->next : l1;
                cur->next = l2;
            } else {
                l2 = l2 ? l2->next : l2;
                cur->next = l1;
            }
            cur = cur->next;
            reversed = !reversed;
        }
    }
private:
    ListNode *findMiddle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *res = slow->next;
        slow->next = NULL;
        return res;
    }
    ListNode *reverse(ListNode *head) {
        ListNode *cur = head, *prev = NULL;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

