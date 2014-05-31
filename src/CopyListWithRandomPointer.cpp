/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_set<RandomListNode *> copied;
        RandomListNode dummy(-1);
        RandomListNode *pre = &dummy;
        while(head) {
            if (copied.find(head) != copied.end()) {
                pre->next = *copied.find(head);
            } else {
                pre->next = new RandomListNode(head->label);
                copied.insert(pre->next);
            }
            if (head->next) {
                if (copied.find(head->next) != copied.end()) {
                    pre->next->next = *copied.find(head->next);
                } else {
                    pre->next->next = new RandomListNode(head->next->label);
                    copied.insert(pre->next->next);
                }
            }
            if (head->random) {
                if (copied.find(head->random) != copied.end()) {
                    pre->next->random = *copied.find(head->random);
                } else {
                    pre->next->random = new RandomListNode(head->random->label);
                    copied.insert(pre->next->random);
                }
            }
            pre = pre->next;
            head = head->next;
        }
        return dummy.next;
    }
};

