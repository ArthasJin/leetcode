// O(nk)
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

// O(nlogk)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Compare {
public:
    bool operator()(ListNode *l1, ListNode *l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() > 0) {
            priority_queue<ListNode *,vector<ListNode *>, Compare> q;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i]) {
                    q.push(lists[i]);
                }
            }
            ListNode dummy(-1);
            ListNode *cur = &dummy;
            while(!q.empty()) {
                ListNode *node = q.top();
                q.pop();
                cur->next = node;
                if (node->next) {
                    q.push(node->next);
                }
                cur = cur->next;
            }
            return dummy.next;
        }
        return NULL;
    }
};

// alternitive
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
        priority_queue<ListNode *, vector<ListNode *>, Solution> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }
        while(!q.empty()) {
            ListNode *node = q.top();
            q.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) {
                q.push(node->next);
            }
        }
        return dummy.next;
    }
    bool operator()(ListNode *lhs, ListNode *rhs) {
        return lhs->val > rhs->val;
    }
};

