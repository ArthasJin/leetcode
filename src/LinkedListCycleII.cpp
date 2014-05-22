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

