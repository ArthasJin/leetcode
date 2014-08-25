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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) {
            return NULL;
        }
        ListNode *p = new ListNode(-1);
        p->next = head;
        head = p;
        ListNode *q = NULL;
        while (p->next != NULL) {
            q = head;
            bool flag = false;
            while (q != p) {
                if (q->next->val > p->next->val) {
                    ListNode* tmp1 = p->next;
                    p->next = p->next->next;
                    tmp1->next = q->next;
                    q->next = tmp1;
                    flag = true;
                    break;
                } else {
                    q = q->next;
                }
            }
            if (!flag) {
                p = p->next;
            }
        }
        return head->next;
    }
};

// more elegant solution
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN);
        ListNode *cur = head;
        while (cur) {
            ListNode *prev = findInsertPlace(&dummy, cur);
            ListNode *tmp = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = tmp;
        }
        return dummy.next;
    }
private:
    ListNode *findInsertPlace(ListNode *p1, ListNode *p2){
        ListNode *prev = NULL, *cur = p1;
        while (cur && cur->val <= p2->val) {
            prev = cur;
            cur = cur->next;
        }
        return prev;
    }
};

