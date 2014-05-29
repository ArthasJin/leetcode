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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        while(isValid(lists)) {
            int minHeadIndex = -1;
            int minVal = INT_MAX;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] && lists[i]->val < minVal) {
                    minHeadIndex = i;
                    minVal = lists[i]->val;
                }
            }
            cur->next = lists[minHeadIndex];
            lists[minHeadIndex] = lists[minHeadIndex]->next;
            cur = cur->next;
        }
        return dummy.next;
    }
private:
    bool isValid(vector<ListNode *> &lists) {
        bool valid = false;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                valid = true;
                break;
            }
        }
        return valid;
    }
};

