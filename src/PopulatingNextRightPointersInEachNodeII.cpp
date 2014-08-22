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
        TreeLinkNode *p = root->next;
        while(p) {
            if (p->left) {
                p = p->left;
                break;
            }
            if (p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) {
            root->right->next = p;
        }
        if (root->left) {
            root->left->next = root->right ? root->right : p;
        }
        connect(root->right);
        connect(root->left);
    }
};

