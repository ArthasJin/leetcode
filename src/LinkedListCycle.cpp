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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> s;
        while(head) {
            if (s.find(head) != s.end()) {
                return true;
            } else {
                s.insert(head);
            }
            head = head->next;
        }
        return false;
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
    bool hasCycle(ListNode *head) {
        if (head) {
            ListNode *slow = head, *fast = head;
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    return true;
                }
            }
            return false;
        }
        return false;
    }
};

