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
    ListNode *partition(ListNode *head, int x) {
        ListNode *p = new ListNode(0);
        p->next = head;
        head = p; // used to save the result head.
        ListNode *last = head; // used to get the last node
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            return head->next;
        }
        int n = 0; //length of the list
        while (last->next) {
            last = last->next;
            n++;
        } //get the length and last node
        while (n > 0) {  // in case  of non-stop loop, count n.
            if (p->next->val < x) {  // val<x keep the node
                p = p->next;
                n--;
            } else {                  // val>=x move to last
                last->next = new ListNode(p->next->val);    // add node to the last
                last = last->next;
                p->next = p->next->next;                    //delete current node
                n--;
            }
        }
        return head->next;  //the 1st node is elmininated
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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *cur = head, *prev = &dummy;
        while (cur && cur->next) {
            if (cur->val >= x) {
                break;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        ListNode *node = cur;
        if (cur) {
            cur = cur->next;
        }
        while (cur) {
            if (cur->val < x) {
                ListNode *tmp1 = cur->next;
                ListNode *tmp2 = prev->next;
                prev->next = cur;
                cur->next = tmp2;
                prev = cur;
                node->next = tmp1;
                cur = tmp1;
            } else {
                cur = cur->next;
                node = node->next;
            }
        }
        return dummy.next;
    }
};

