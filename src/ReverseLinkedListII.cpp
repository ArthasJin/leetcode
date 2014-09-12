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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *h = head;
        for (int i = 0; i < n - m; i++) {
            int k1 = m + i;
            int k2 = n - i;
            if (k1 >= k2) {
                return head;
            }
            ListNode *p = h;
            ListNode *q = h;
            while (k1 - 1 > 0) {
                p = p->next;
                k1--;
            }
            while (k2 - 1 > 0) {
                q = q->next;
                k2--;
            }
            int tmp = p->val;
            p->val = q->val;
            q->val = tmp;
        }
        return head;
    }
};

// alternative
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head) {
            ListNode dummy(-1);
            dummy.next = head;
            ListNode *cur = &dummy, *prev = NULL;
            int k = n - m;
            if (k == 0) {
                return dummy.next;
            }
            while (m--) {
                prev = cur;
                cur = cur->next;
            }
            while (k--) {
                ListNode *tmp1 = prev->next;
                ListNode *tmp2 = cur->next;
                prev->next = cur->next;
                cur->next = tmp2->next;
                tmp2->next = tmp1;
            }
            return dummy.next;
        }
        return NULL;
    }
};

