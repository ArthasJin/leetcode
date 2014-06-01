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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int len = length(head);
        k %= len;
        if (len <= 1 || k == 0) {
            return head;
        }
        int step = len - k;
        ListNode *pre = NULL, *cur = head;
        while(step--) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
        ListNode *res = cur;
        while(cur && cur->next) {
            cur = cur->next;
        }
        cur->next = head;
        return res;
    }
private:
    int length(ListNode *head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }
};

