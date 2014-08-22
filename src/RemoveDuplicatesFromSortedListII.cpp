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
        dummy.next = head;
        ListNode *cur = &dummy;
        while(cur && cur->next) {
            ListNode *p = cur->next->next;
            bool dup = false;
            while(p && p->val == cur->next->val) {
                p = p->next;
                dup = true;
            }
            if (dup) {
                cur->next = p;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};

