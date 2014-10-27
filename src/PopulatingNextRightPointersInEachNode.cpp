/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root) {
            traversal(root);
            for (int i = 0; i < res.size(); ++i) {
                vector<TreeLinkNode *> level = res[i];
                for (int j = 0; j < level.size() - 1; ++j) {
                    level[j]->next = level[j + 1];
                }
            }
        }
    }
private:
    vector<vector<TreeLinkNode *> > res;
    void traversal(TreeLinkNode *root) {
        queue<TreeLinkNode *> q1, q2;
        q1.push(root);
        while(!q1.empty()) {
            vector<TreeLinkNode *> level;
            while(!q1.empty()) {
                TreeLinkNode *node = q1.front();
                q1.pop();
                level.push_back(node);
                if (node->left) {
                    q2.push(node->left);
                }
                if (node->right) {
                    q2.push(node->right);
                }
            }
            swap(q1, q2);
            res.push_back(level);
        }
    }
};

// recursive
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        if (root->left) {
            root->left->next = root->right;
        }
        if (root->next && root->right) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};

// alternative
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        queue<TreeLinkNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeLinkNode *head = q.front();
            q.pop();
            int size = q.size();
            if (head->left) {
                q.push(head->left);
            }
            if (head->right) {
                q.push(head->right);
            }
            for (int i = 0; i < size; ++i) {
                TreeLinkNode *node = q.front();
                q.pop();
                head->next = node;
                head = head->next;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
    }
};

