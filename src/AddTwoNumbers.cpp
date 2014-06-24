// space O(n)
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *pre = &dummy, *cur1 = l1, *cur2 = l2;
        int carry = 0;
        while(cur1 || cur2) {
            int val1 = cur1? cur1->val : 0;
            int val2 = cur2? cur2->val : 0;
            int sum = val1 + val2 + carry;
            pre->next = new ListNode(sum % 10);
            pre = pre->next;
            carry = sum / 10;
            cur1 = cur1? cur1->next : NULL;
            cur2 = cur2? cur2->next : NULL;
        }
        if (carry) {
            pre->next = new ListNode(1);
        }
        return dummy.next;
    }
};

// space O(1)
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        int carry = 0;
        while(l1 || l2) {
            int val1 = l1? l1->val : 0;
            int val2 = l2? l2->val : 0;
            int val = val1 + val2 + carry;
            carry = val / 10;
            if (l1) {
                l1->val = val % 10;
                cur->next = l1;
            } else {
                l2->val = val % 10;
                cur->next = l2;
            }
            l1 = l1? l1->next : l1;
            l2 = l2? l2->next : l2;
            cur = cur->next;
        }
        if (carry) {
            cur->next = new ListNode(1);
        }
        return dummy.next;
    }
};

