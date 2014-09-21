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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head) return head;
        ListNode dummy(0), *pos = &dummy;
        dummy.next = head;
        while (pos) {
            int copy_k = k;
            ListNode *cur = pos;
            while (copy_k-- && cur) {
                cur = cur->next;
            }
            if (!cur) {
                break;
            }
            copy_k = k;
            cur = pos->next;
            while (--copy_k) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pos->next;
                pos->next = tmp;
            }
            pos = cur;
        }
        return dummy.next;
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *cur = head, *prev = &dummy;
        while (cur) {
            ListNode *cur = prev->next;
            int copy = k;
            while (--copy && cur) {
                cur = cur->next;
            }
            if (!cur) {
                break;
            }
            copy = k;
            cur = prev->next;
            while (--copy) {
                ListNode *tmp1 = cur->next;
                ListNode *tmp2 = prev->next;
                prev->next = tmp1;
                cur->next = tmp1->next;
                tmp1->next = tmp2;
            }
            prev = cur;
        }
        return dummy.next;
    }
};

