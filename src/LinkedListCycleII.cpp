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
    ListNode *detectCycle(ListNode *head) {
        if (head) {
            ListNode *first = head;
            ListNode *second = head;
            while(first && second) {
                first = first->next;
                second = second->next;
                if (second) {
                    second = second->next;
                }
                if (first == second) {
                    break;
                }
            }
            if (!second) {
                return NULL;
            }
            first = head;
            while(first != second) {
                first = first->next;
                second = second->next;
            }
            return first;
        }
        return NULL;
    }
};

// updated
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
    ListNode *detectCycle(ListNode *head) {
        if (head) {
            ListNode *slow = head, *fast = head;
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    break;
                }
            }
            if (!fast || !fast->next) {
                return NULL;
            }
            if (slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

