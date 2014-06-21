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
    ListNode *sortList(ListNode *head) {
        mergeSort(&head);
        return head;
    }
private:
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        while(l1 || l2) {
            int val1 = l1? l1->val : INT_MAX;
            int val2 = l2? l2->val : INT_MAX;
            if (val1 < val2) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
    void split(ListNode *head, ListNode **la, ListNode **lb) {
        ListNode *slow, *fast, *pre;
        if (!head || !head->next) {
            *la = head;
            *lb = NULL;
        } else {
            slow = fast = head;
            pre = NULL;
            while(fast && fast->next) {
                fast = fast->next->next;
                pre = slow;
                slow = slow->next;
            }
            *la = head;
            *lb = slow;
            pre->next = NULL;
        }
    }
    void mergeSort(ListNode **head) {
        ListNode *p = *head;
        if (p && p->next) {
            ListNode *left = NULL, *right = NULL;
            split(p, &left, &right);
            mergeSort(&left);
            mergeSort(&right);
            *head = merge(left, right);
        }
    }
};

