// 3Sum.cpp
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        set<vector<int> > s;
        if (num.size() > 2) {
            sort(num.begin(), num.end());
            for (int i = 0; i < num.size() - 2; ++i) {
                while(i - 1 > 0 && i < num.size() - 2 && num[i] == num[i - 1]) {
                    ++i;
                }
                int low = i + 1, high = num.size() - 1;
                while(low < high) {
                    int sum = num[i] + num[low] + num[high];
                    if (sum == 0) {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[low]);
                        v.push_back(num[high]);
                        s.insert(v);
                        high--;
                        low++;
                    } else if (sum > 0) {
                        high--;
                    } else if (sum < 0) {
                        low++;
                    }
                }
            }
        }
        vector<vector<int> > res;
        res.assign(s.begin(), s.end());
        return res;
    }
};


// 3SumClosest.cpp
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) return 0;
        sort(num.begin(), num.end());
        int res = num[0] + num[1] + num[2];
        for (int i = 0 ; i < num.size(); ++i) {
            int low = i + 1, high = num.size() - 1;
            while(low < high) {
                int sum = num[i] + num[low] + num[high];
                if (sum > target) {
                    high--;
                } else if (sum < target) {
                    low++;
                } else {
                    return sum;
                }
                if (abs(target - sum) < abs(target - res)) {
                    res = sum;
                }
            }
        }
        return res;
    }
};


// 4Sum.cpp
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        set<vector<int> > s;
        if (num.size() > 2) {
            sort(num.begin(), num.end());
            for (int i = 0; i < num.size() - 3; ++i) {
                for (int j = i + 1; j < num.size() - 2; ++j) {
                    int low = j + 1;
                    int high = num.size() - 1;
                    while(low < high) {
                        int sum = num[i] + num[j] + num[low] + num[high];
                        if (sum > target) {
                            high--;
                        } else if (sum < target) {
                            low++;
                        } else {
                            vector<int> path;
                            path.push_back(num[i]);
                            path.push_back(num[j]);
                            path.push_back(num[low]);
                            path.push_back(num[high]);
                            s.insert(path);
                            low++, high--;
                        }
                    }
                }
            }
        }
        vector<vector<int> > res;
        res.assign(s.begin(), s.end());
        return res;
    }
};


// AddBinary.cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = 0, carry = 0;
        while(i < a.length() || i < b.length()) {
            int val1 = i < a.length()? a[a.length() - 1 - i] - '0' : 0;
            int val2 = i < b.length()? b[b.length() - 1 - i] - '0' : 0;
            int sum = val1 + val2 + carry;
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
            i++;
        }
        if (carry) {
            res.push_back(1 + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// AddTwoNumbers.cpp
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *pre = &dummy, *cur1 = l1, *cur2 = l2;
        int carry = 0;
        while(cur1 || cur2) {
            int val1 = cur1? cur1->val : 0;
            int val2 = cur2? cur2->val : 0;
            int sum = val1 + val2 + carry;
            pre->next = new ListNode(sum % 10);
            pre = pre->next;
            carry = sum / 10;
            cur1 = cur1? cur1->next : NULL;
            cur2 = cur2? cur2->next : NULL;
        }
        if (carry) {
            pre->next = new ListNode(1);
        }
        return dummy.next;
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        int carry = 0;
        while(l1 || l2) {
            int val1 = l1? l1->val : 0;
            int val2 = l2? l2->val : 0;
            int val = val1 + val2 + carry;
            carry = val / 10;
            if (l1) {
                l1->val = val % 10;
                cur->next = l1;
            } else {
                l2->val = val % 10;
                cur->next = l2;
            }
            l1 = l1? l1->next : l1;
            l2 = l2? l2->next : l2;
            cur = cur->next;
        }
        if (carry) {
            cur->next = new ListNode(1);
        }
        return dummy.next;
    }
};


// Anagrams.cpp
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string, int> dict;
        if (strs.size() > 0) {
            for (int i = 0; i < strs.size(); ++i) {
                string s = strs[i];
                sort(s.begin(), s.end());
                if (dict.find(s) != dict.end()) {
                    res.push_back(strs[i]);
                    if (dict[s] != -1) {
                        res.push_back(strs[dict[s]]);
                        dict[s] = -1;
                    }
                } else {
                    dict[s] = i;
                }
            }
        }
        return res;
    }
};


// BalancedBinaryTree.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalanced(root, depth);
    }
private:
    bool isBalanced(TreeNode *root, int &depth) {
        if (!root) {
            return true;
        }
        int leftDepth = 0, rightDepth = 0;
        bool leftBalanced = isBalanced(root->left, leftDepth);
        bool rightBalanced = isBalanced(root->right, rightDepth);
        depth = leftDepth > rightDepth? leftDepth + 1 : rightDepth + 1;
        return leftBalanced && rightBalanced && abs(leftDepth - rightDepth) < 2;
    }
};

// more elegant solution
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root) {
            return isBalanced(root->left) && isBalanced(root->right) && abs(maxDepth(root->left) - maxDepth(root->right)) < 2;
        }
        return true;
    }
private:
    int maxDepth(TreeNode *root) {
        if (root) {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
        return 0;
    }
};


// BestTimeToBuyAndSellStock.cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() > 1) {
            int minPrice = INT_MAX;
            int profit = INT_MIN;
            for (int i = 0; i < prices.size(); ++i) {
                minPrice = min(minPrice, prices[i]);
                profit = max(profit, prices[i] - minPrice);
            }
            return profit;
        }
        return 0;
    }
};


// BestTimeToBuyAndSellStockII.cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};


// BestTimeToBuyAndSellStockIII.cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() > 1) {
            vector<int> left(prices.size(), 0);
            vector<int> right(prices.size(), 0);
            int profit = 0, minPrice = INT_MAX;
            for (int i = 0; i < prices.size(); ++i) {
                minPrice = min(minPrice, prices[i]);
                profit = max(profit, prices[i] - minPrice);
                left[i] = profit;
            }
            int maxPrice = INT_MIN;
            profit = 0;
            for (int i = prices.size() - 1; i >= 0; --i) {
                maxPrice = max(maxPrice, prices[i]);
                profit = max(profit, maxPrice - prices[i]);
                right[i] = profit;
            }
            profit = 0;
            for (int i = 0; i < prices.size(); ++i) {
                profit = max(left[i] + right[i], profit);
            }
            return profit;
        }
        return 0;
    }
};


// BinaryTreeInorderTraversal.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        traversal(root);
        return res;
    }
private:
    vector<int> res;
    void traversal(TreeNode *root) {
        if (root) {
            traversal(root->left);
            res.push_back(root->val);
            traversal(root->right);
        }
    }
};

// iterative
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        while(root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};


// BinaryTreeLevelOrderTraversal.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        if (root) {
            traversal(root);
        }
        return res;
    }
private:
    vector<vector<int> > res;
    void traversal(TreeNode *root) {
        queue<TreeNode *> q1, q2;
        q1.push(root);
        while(!q1.empty()) {
            vector<int> level;
            while(!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                level.push_back(node->val);
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


// BinaryTreeLevelOrderTraversalII.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        if (root) {
            traversal(root);
        }
        reverse(res.begin(), res.end());
        return res;
    }
private:
    vector<vector<int> > res;
    void traversal(TreeNode *root) {
        queue<TreeNode *> q1, q2;
        q1.push(root);
        while(!q1.empty()) {
            vector<int> level;
            while(!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                level.push_back(node->val);
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


// BinaryTreeMaximumPathSum.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (root) {
            maxSum = INT_MIN;
            pathSum(root);
        }
        return maxSum;
    }
private:
    int maxSum;
    int pathSum(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = pathSum(root->left);
        int right = pathSum(root->right);
        int sum = root->val;
        if (left > 0) {
            sum += left;
        }
        if (right > 0) {
            sum += right;
        }
        maxSum = max(maxSum, sum);
        if (left < 0 && right < 0) {
            return root->val;
        } else {
            return root->val + max(left, right);
        }
    }
};


// BinaryTreePostorderTraversal.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        traversal(root);
        return res;
    }
private:
    vector<int> res;
    void traversal(TreeNode *root) {
        if (root) {
            traversal(root->left);
            traversal(root->right);
            res.push_back(root->val);
        }
    }
};


// BinaryTreePreorderTraversal.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        traversal(root);
        return res;
    }
private:
    vector<int> res;
    void traversal(TreeNode *root) {
        if (root) {
            res.push_back(root->val);
            traversal(root->left);
            traversal(root->right);
        }
    }
};


// BinaryTreeZigzagLevelOrderTraversal.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if (root) {
            traversal(root);
        }
        return res;
    }
private:
    vector<vector<int> > res;
    void traversal(TreeNode *root) {
        queue<TreeNode *> q1, q2;
        bool reversed = false;
        q1.push(root);
        while(!q1.empty()) {
            vector<int> level;
            while(!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                level.push_back(node->val);
                if (node->left) {
                    q2.push(node->left);
                }
                if (node->right) {
                    q2.push(node->right);
                }
            }
            if (reversed) {
                reverse(level.begin(), level.end());
                reversed = false;
            } else {
                reversed = true;
            }
            swap(q1, q2);
            res.push_back(level);
        }
    }
};


// Candy.cpp
class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> left(ratings.size(), 1);
        vector<int> right(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < ratings.size(); ++i) {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};


// ClimbingStairs.cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        int fn_1 = 1;
        int fn_2 = 1;
        int fn = fn_1 + fn_2;
        for (int i = 1; i < n; ++i) {
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
};


// CloneGraph.cpp
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node) {
            return clone(node);
        }
        return NULL;
    }
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
    UndirectedGraphNode *clone(UndirectedGraphNode *node) {
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        visited[node] = copy;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            if (visited.find(node->neighbors[i]) == visited.end()) {
                copy->neighbors.push_back(clone(node->neighbors[i]));
            } else {
                copy->neighbors.push_back(visited[node->neighbors[i]]);
            }
        }
        return copy;
    }
};


// CombinationSum.cpp
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> selected(candidates.size());
        combine(candidates, 0, target, selected);
        vector<vector<int> > res;
        res.assign(s.begin(), s.end());
        return res;
    }
private:
    set<vector<int> > s;
    void combine(vector<int> &num, int index, int target, vector<int> &selected) {
        if (index == num.size()) {
            if (target == 0) {
                vector<int> entry;
                for (int i = 0; i < selected.size(); ++i) {
                    for (int j = 0; j < selected[i]; ++j) {
                        entry.push_back(num[i]);
                    }
                }
                s.insert(entry);
            }
            return;
        }
        int n = target / num[index];
        for (int i = 0; i < n + 1; ++i) {
            selected[index] = i;
            combine(num, index + 1, target - i * num[index], selected);
        }
    }
};

// alternative
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> entry;
        combine(candidates, 0, target, entry);
        vector<vector<int> > res;
        res.assign(s.begin(), s.end());
        return res;
    }
private:
    set<vector<int> > s;
    void combine(vector<int> &can, int index, int target, vector<int> &entry) {
        if (target < 0 || index == can.size()) {
            return;
        }
        if (target == 0) {
            s.insert(entry);
            return;
        }
        for (int i = index; i < can.size(); ++i) {
            entry.push_back(can[i]);
            combine(can, i, target - can[i], entry);
            entry.pop_back();
        }
    }
};


// CombinationSumII.cpp
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> entry;
        sort(num.begin(), num.end());
        combine(num, 0, target, entry);
        vector<vector<int> > res;
        res.assign(s.begin(), s.end());
        return res;
    }
private:
    set<vector<int> > s;
    void combine(vector<int> &num, int index, int target, vector<int> &entry) {
        if (target == 0 && !entry.empty()) {
            s.insert(entry);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            if (target < num[i]) return;
            entry.push_back(num[i]);
            combine(num, i + 1, target - num[i], entry);
            entry.pop_back();
        }
    }
};


// Combinations.cpp
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> input;
        for (int i = 0; i < n; ++i) {
            input.push_back(i + 1);
        }
        vector<int> entry;
        combine(input, 0, k, entry);
        return res;
    }
private:
    vector<vector<int> > res;
    void combine(vector<int> &input, int index, int k, vector<int> &entry) {
        if (!entry.empty() && entry.size() == k) {
            res.push_back(entry);
            return;
        }
        for (int i = index; i < input.size(); ++i) {
            entry.push_back(input[i]);
            combine(input, i + 1, k, entry);
            entry.pop_back();
        }
    }
};


// ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() > 0 && postorder.size() > 0) {
            return build(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
        }
        return NULL;
    }
private:
    TreeNode *build(vector<int> &inorder, int start, int end, vector<int> &postorder, int postEnd) {
        if (start > end) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int mid = 0;
        for (int i = start; i < end + 1; ++i) {
            if (postorder[postEnd] == inorder[i]) {
                mid = i;
                break;
            }
        }
        root->left = build(inorder, start, mid - 1, postorder, postEnd - end + mid - 1);
        root->right = build(inorder, mid + 1, end, postorder, postEnd - 1);
        return root;
    }
};


// ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() > 0 && inorder.size() > 0) {
            return build(preorder, 0, inorder, 0, inorder.size() - 1);
        }
        return NULL;
    }
private:
    TreeNode *build(vector<int> &preorder, int preStart, vector<int> &inorder, int start, int end) {
        if (start > end) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int mid = 0;
        for (int i = start; i < end + 1; ++i) {
            if (preorder[preStart] == inorder[i]) {
                mid = i;
                break;
            }
        }
        root->left = build(preorder, preStart + 1, inorder, start, mid - 1);
        root->right = build(preorder, preStart + mid + 1 - start, inorder, mid + 1, end);
        return root;
    }
};


// ContainerWithMostWater.cpp
class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        if (height.size() > 1) {
            int low = 0, high = height.size() - 1;
            while(low < high) {
                res = max(res, min(height[low], height[high]) * (high - low));
                if (height[low] < height[high]) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        return res;
    }
};


// ConvertSortedArrayToBinarySearchTree.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return toBST(num, 0, num.size() - 1);
    }
private:
    TreeNode* toBST(vector<int> &num, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (end + start) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = toBST(num, start, mid - 1);
        node->right = toBST(num, mid + 1, end);
        return node;
    }
};


// ConvertSortedListToBinarySearchTree.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        ListNode *p = head;
        while(p) {
            p = p->next;
            n++;
        }
        return buildBST(head, 1, n);
    }
private:
    TreeNode *buildBST(ListNode* &head, int start, int end) {
        if (start > end) {
            return NULL;
        }
        TreeNode *left = buildBST(head, start, start + (end - start) / 2 - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        TreeNode *right = buildBST(head, start + (end - start) / 2 + 1, end);
        root->left = left;
        root->right = right;
        return root;
    }
};


// CopyListWithRandomPointer.cpp
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

// alternative
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
        RandomListNode dummy(-1);
        RandomListNode *cur = &dummy;
        unordered_map<RandomListNode *, RandomListNode *> copied;
        while (head) {
            if (copied.find(head) != copied.end()) {
                cur->next = copied[head];
            } else {
                cur->next = new RandomListNode(head->label);
                copied[head] = cur->next;
            }
            if (head->random) {
                if (copied.find(head->random) != copied.end()) {
                    cur->next->random = copied[head->random];
                } else {
                    cur->next->random = new RandomListNode(head->random->label);
                    copied[head->random] = cur->next->random;
                }
            }
            head = head->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};


// CountAndSay.cpp
class Solution {
public:
    string countAndSay(int n) {
        int current = n;
        if (current < 1) {
            return string();
        }
        string res = "1", tmp = "";
        for (int i = 1; i < n; ++i) {
            int length = res.length();
            int count = 1;
            for (int j = 0; j < length - 1; ++j) {
                if (res[j] == res[j + 1]) {
                    count++;
                    continue;
                } else {
                    tmp += char('0' + count);
                    tmp += res[j];
                    count = 1;
                }
            }
            tmp += char('0' + count);
            tmp += res[length - 1];
            res = tmp;
            tmp = "";
        }
        return res;
    }
};

// more elegant solution
class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) {
            return string();
        }
        string res = "1", tmp = "";
        for (int i = 1; i < n; ++i) {
            int len = res.length();
            int count = 1;
            for (int j = 0; j < len - 1; ++j) {
                if (res[j] == res[j + 1]) {
                    count++;
                } else {
                    tmp += '0' + count;
                    tmp += res[j];
                    count = 1;
                }
            }
            tmp += '0' + count;
            tmp += res[len - 1];
            res = tmp;
            tmp = "";
        }
        return res;
    }
};

// more elegant solution
class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        for (int i = 1; i < n; ++i) {
            char cur = prev[0];
            int count = 1;
            string tmp;
            for (int j = 1; j < prev.length() + 1; ++j) {
                if (prev[j] == cur) {
                    count++;
                } else {
                    tmp += count + '0';
                    tmp.push_back(cur);
                    cur = prev[j];
                    count = 1;
                }
            }
            prev = tmp;
        }
        return prev;
    }
};


// DecodeWays.cpp
// dfs TLE
class Solution {
public:
    int numDecodings(string s) {
        for (int i = 0; i < 26; ++i) {
            alpha.push_back('A' + i);
        }
        decode(s, 0);
        return res;
    }
private:
    vector<char> alpha;
    int res;
    bool isValid(string &s) {
        if (s.length() == 1) {
            return s[0] >= '1' && s[0] <= '9';
        } else if (s.length() == 2) {
            int num = atoi(s.c_str());
            return s[0] != '0' && num > 10 && num <= 26;
        }
        return false;
    }
    void decode(string &s, int start) {
        if (start >= s.length()) {
            res++;
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            string sub = s.substr(i, 1);
            if (isValid(sub)) {
                decode(s, i + 1);
            }
            if (i + 1 < s.length()) {
                sub = s.substr(i, 2);
                if (isValid(sub)) {
                    decode(s, i + 2);
                }
            }
        }
    }
};

// dp
class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        vector<int> dp(s.length());
        string sub = s.substr(0, 1);
        if (isValid(sub)) {
            dp[0] = 1;
        }
        if (s.length() == 1) {
            return dp[0];
        }
        sub = s.substr(0, 2);
        if (isValid(sub)) {
            dp[1] = 1;
        }
        sub = s.substr(1, 1);
        if (s[0] != '0' && isValid(sub)) {
            dp[1]++;
        }
        for (int i = 2; i < s.length(); ++i) {
            sub = s.substr(i, 1);
            if (isValid(sub)) dp[i] += dp[i - 1];
            sub = s.substr(i - 1, 2);
            if (isValid(sub)) dp[i] += dp[i - 2];
        }
        return dp[s.length() - 1];
    }
private:
    bool isValid(string &s) {
        if (s.length() == 1) {
            return s[0] >= '1' && s[0] <= '9';
        } else if (s.length() == 2) {
            int num = atoi(s.c_str());
            return s[0] != '0' && num >= 10 && num <= 26;
        }
        return false;
    }
};


// DistinctSubsequences.cpp
class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.length();
        int n = T.length();
        if (m < n) return 0;
        vector<vector<int> > dp(m, vector<int>(n));
        if (S[0] == T[0]) dp[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            if (S[i] == T[0]) {
                dp[i][0] = dp[i - 1][0] + 1;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (S[i] == T[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// alternative
class Solution {
public:
    int numDistinct(string S, string T) {
        int record[200];
        for (int i = 1; i < 200; i++) {
            record[i] = 0;
        }
        record[0] = 1;
        for (int i = 1; i < S.size() + 1; ++i) {
            for (int j = T.size(); j >= 1; --j) {
                if (S[i - 1] == T[j - 1]) {
                    record[j] += record[j - 1];
                }
            }
        }
        return record[T.size()];
    }
};


// DivideTwoIntegers.cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((double) dividend);
        long long b = abs((double) divisor);
        long long res = 0;
        while(a >= b) {
            long long c = b;
            for (int i = 0; a >= c; ++i, c <<= 1) {
                a -= c;
                res += 1 << i;
            }
        }
        return (dividend ^ divisor) >> 31 ? -res : res;
    }
};


// EditDistance.cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() > 0 && word2.length() > 0) {
            vector<vector<int> > dp(word1.length() + 1, vector<int>(word2.length() + 1));
            for (int i = 0; i < word1.length() + 1; ++i) {
                dp[i][0] = i;
            }
            for (int j = 0; j < word2.length() + 1; ++j) {
                dp[0][j] = j;
            }
            for (int i = 1; i < word1.length() + 1; ++i) {
                for (int j = 1; j < word2.length() + 1; ++j) {
                    int diff = word1[i - 1] == word2[j - 1]? 0 : 1;
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + diff);
                }
            }
            return dp[word1.length()][word2.length()];
        }
        return word1.length() == 0? word2.length() : word1.length();
    }
};


// EvaluateReversePolishNotation.cpp
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() > 0) {
            stack<int> stk;
            for (int i = 0; i < tokens.size(); ++i) {
                if (tokens[i] == "+") {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op1 + op2);
                } else if (tokens[i] == "-") {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op2 - op1);
                } else if (tokens[i] == "*") {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op2 * op1);
                } else if (tokens[i] == "/") {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op2 / op1);
                } else {
                    stk.push(atoi(tokens[i].c_str()));
                }
            }
            return stk.top();
        }
        return 0;
    }
};

// more elegant solution
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        string ops = "+-*/";
        stack<int> stk;
        for (int i = 0; i < tokens.size(); ++i) {
            int op = ops.find(tokens[i]);
            if (op != string::npos) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(eval(a, b, ops[op]));
            } else {
                stk.push(atoi(&tokens[i][0]));
            }
        }
        return stk.top();
    }
private:
    int eval(int &n1, int &n2, char op) {
        switch(op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        }
    }
};


// FirstMissingPositive.cpp
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(A[i]);
        }
        for (int i = 1; i < n + 2; ++i) {
            if (s.find(i) == s.end()) {
                return i;
            }
        }
        return 1;
    }
};

// updated
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        unordered_set<int> dict;
        for (int i = 0; i < n; ++i) {
            dict.insert(A[i]);
        }
        for (int i = 1; i < n + 1; ++i) {
            if (dict.find(i) == dict.end()) {
                return i;
            }
        }
        return n + 1;
    }
};

// space O(1)
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while(i < n) {
            if (A[i] > 0 && A[i] < n + 1 && A[i] != i + 1 && A[i] != A[A[i] - 1]) {
                swap(A[A[i] - 1], A[i]);
            } else {
                i++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};


// FlattenBinaryTreeToLinkedList.cpp
// inorder traverse
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        traverse(root);
        for (int i = 1; i < path.size(); ++i) {
            path[i - 1]->left = NULL;
            path[i - 1]->right = path[i];
        }
    }
private:
    vector<TreeNode *> path;
    void traverse(TreeNode *root) {
        if (!root) {
            return;
        }
        path.push_back(root);
        traverse(root->left);
        traverse(root->right);
    }
};

// in-place
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        while(root) {
            TreeNode *pre = root->left;
            if (pre) {
                while(pre->right) {
                    pre = pre->right;
                }
                pre->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};


// GasStation.cpp
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() > 0) {
            int tank = 0, i = 0, j = 0, n = gas.size();
            while(i < n) {
                if (j > n) {
                    return i;
                }
                int net = 0;
                if (i + j >= n) {
                    net = gas[i + j - n] - cost[i + j - n];
                } else {
                    net = gas[i + j] - cost[i + j];
                }
                if (tank + net < 0) {
                    j++;
                    i = i + j;
                    tank = 0;
                    j = 0;
                } else {
                    tank += net;
                    j++;
                }
            }
        }
        return -1;
    }
};

// more elegant solution
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0, total = 0, j = -1;
        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += sum;
            if (sum < 0) {
                j = i;
                sum = 0;
            }
        }
        if (total < 0) {
            return -1;
        } else {
            return j + 1;
        }
    }
};


// GenerateParentheses.cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string input;
        generate(n, 0, input);
        return res;
    }
private:
    vector<string> res;
    bool isValid(string &input) {
        int flag = 0;
        for (int i = 0; i < input.length(); ++i) {
            if (flag < 0) {
                return false;
            } else if (input[i] == '(') {
                flag++;
            } else if (input[i] == ')') {
                flag--;
            }
        }
        return flag == 0;
    }
    void generate(int n, int index, string &input) {
        if (n * 2 == index) {
            if (isValid(input)) {
                res.push_back(input);
            }
            return;
        }
        input.push_back('(');
        generate(n, index + 1, input);
        input.pop_back();
        input.push_back(')');
        generate(n, index + 1, input);
        input.pop_back();
    }
};


// GrayCode.cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int code = pow(2, n);
        for (int i = 0; i < code; ++i) {
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};


// ImplementStrStr.cpp
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        string s(haystack);
        if (s.find(needle) != string::npos) {
            return haystack + s.find(needle);
        }
        return NULL;
    }
};


// InsertInterval.cpp
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        list<Interval> l;
        l.assign(intervals.begin(), intervals.end());
        list<Interval>::iterator iter = l.begin();
        vector<Interval> res;
        while(iter != l.end()) {
            if (newInterval.end < iter->start) {
                l.insert(iter, newInterval);
                res.assign(l.begin(), l.end());
                return res;
            } else if (newInterval.start > iter->end) {
                iter++;
                continue;
            } else {
                newInterval.start = min(iter->start, newInterval.start);
                newInterval.end = max(iter->end, newInterval.end);
                iter = l.erase(iter);
            }
        }
        l.push_back(newInterval);
        res.assign(l.begin(), l.end());
        return res;
    }
};

// space O(1)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator iter = intervals.begin();
        while (iter != intervals.end()) {
            if (newInterval.end < iter->start) {
                intervals.insert(iter, newInterval);
                return intervals;
            } else if (newInterval.start > iter->end) {
                iter++;
            } else {
                newInterval.start = min(iter->start, newInterval.start);
                newInterval.end = max(iter->end, newInterval.end);
                intervals.erase(iter);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};


// InsertionSortList.cpp
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


// IntegerToRoman.cpp
class Solution {
public:
    string intToRoman(int num) {
        char symbols[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
        string roman;
        int scale = 1000;
        for (int i = 6; i >= 0; i -= 2) {
            int digit = num / scale;
            numToRoman(digit, roman, symbols + i);
            num %= scale;
            scale /= 10;
        }
        return roman;
    }
private:
    void numToRoman(int num, string &roman, char symbols[]) {
        if (num == 0) {
            return;
        } else if (num < 4) {
            roman.append(num, symbols[0]);
        } else if (num == 4) {
            roman.append(1, symbols[0]);
            roman.append(1, symbols[1]);
        } else if (num < 9) {
            roman.append(1, symbols[1]);
            roman.append(num - 5, symbols[0]);
        } else {
            roman.append(1, symbols[0]);
            roman.append(1, symbols[2]);
        }
    }
};

// more elegant solution
class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbols = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        vector<int> roman = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string res;
        for (int i = 0; i < symbols.size(); ++i) {
            while(num >= roman[i]) {
                res.append(symbols[i]);
                num -= roman[i];
            }
        }
        return res;
    }
};


// InterleavingString.cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() > 0 && s1.length() + s2.length() == s3.length()) {
            vector<vector<bool> > dp(s1.length() + 1, vector<bool>(s2.length() + 1));
            dp[0][0] = true;
            for (int i = 1; i < dp.size(); ++i) {
                if (s1[i - 1] == s3[i - 1] && dp[i - 1][0]) {
                    dp[i][0] = true;
                }
            }
            for (int j = 1; j < dp[0].size(); ++j) {
                if (s2[j - 1] == s3[j - 1] && dp[0][j - 1]) {
                    dp[0][j] = true;
                }
            }
            for (int i = 1; i < dp.size(); ++i) {
                for (int j = 1; j < dp[0].size(); ++j) {
                    if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] || s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
            return dp[s1.length()][s2.length()];
        }
        return s1.length() == 0 && s2.length() == 0 && s3.length() == 0;
    }
};


// JumpGame.cpp
class Solution {
public:
    bool canJump(int A[], int n) {
        int reach = 1;
        for (int i = 0; i < reach && i < n; ++i) {
            reach = max(reach, i + 1 + A[i]);
        }
        return reach >= n;
    }
};


// JumpGameII.cpp
class Solution {
public:
    int jump(int A[], int n) {
        if (n > 1) {
            int start = 0, end = 0, step = 0;
            while(end < n) {
                int index = 0;
                step++;
                for (int i = start; i < end + 1; ++i) {
                    if (A[i] + i > index) {
                        index = A[i] + i;
                        start = i + 1;
                    }
                    if (index >= n - 1) {
                        return step;
                    }
                }
                end = index;
            }
        }
        return 0;
    }
};

// alternative
class Solution {
public:
    int jump(int A[], int n) {
        if (A) {
            int i = n - 1;
            int step = 0;
            while (i > 0) {
                for (int j = 0; j < i; ++j) {
                    if (A[j] + j >= i) {
                        i = j;
                        step++;
                        break;
                    }
                }
            }
            return step;
        }
        return -1;
    }
};


// LRUCache.cpp
class LRUCache{
public:
    LRUCache(int capacity) {
        mCapacity = capacity;
    }

    int get(int key) {
        if (mCache.find(key) != mCache.end()) {
            update(key);
            return mCache[key]->value;
        }
        return -1;
    }

    void set(int key, int value) {
        if (mCache.find(key) != mCache.end()) {
            mCache[key]->value = value;
            update(key);
        } else {
            CacheEntry entry(key, value);
            if (mCache.size() == mCapacity) {
                CacheEntry lastEntry = mList.back();
                mCache.erase(lastEntry.key);
                mList.pop_back();
            }
            mList.push_front(entry);
            mCache[key] = mList.begin();
        }
    }
private:
    typedef struct CacheEntry {
        public:
        int key;
        int value;
        CacheEntry(int k, int v) :key(k), value(v) {}
    } CacheEntry;

    int mCapacity;
    unordered_map<int, list<CacheEntry>::iterator> mCache;
    list<CacheEntry> mList;

    void update(int key) {
        CacheEntry entry = *mCache[key];
        mList.erase(mCache[key]);
        mList.push_front(entry);
        mCache[key] = mList.begin();
    }
};


// LargestRectangleInHistogram.cpp
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> stk;
        height.push_back(0);
        int i = 0, area = 0;
        while(i < height.size()) {
            if (stk.empty() || height[i] > height[stk.top()]) {
                stk.push(i++);
            } else {
                int t = stk.top();
                stk.pop();
                area = max(area, height[t] * (stk.empty()? i : i - stk.top() - 1));
            }
        }
        return area;
    }
};


// LengthOfLastWord.cpp
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s) {
            string str(s);
            int last = str.find_last_not_of(" ");
            int start = last;
            while(start >= 0 && str[start] != ' ') {
                start--;
            }
            return last - start;
        }
        return 0;
    }
};


// LetterCombinationsOfAPhoneNumber.cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> dict;
        dict['1'] = "";
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";
        dict['0'] = " ";
        if (digits.length() > 0) {
            vector<string> v;
            for(int i = 0; i < digits.length(); ++i) {
                v.push_back(dict[digits[i]]);
            }
            string entry;
            combine(v, 0, entry);
            return res;
        }
        res.push_back("");
        return res;
    }
private:
    vector<string> res;
    void combine(vector<string> &v, int index, string &entry) {
        if (index == v.size()) {
            res.push_back(entry);
            return;
        }
        for (int i = 0; i < v[index].size(); ++i) {
            entry.push_back(v[index][i]);
            combine(v, index + 1, entry);
            entry.pop_back();
        }
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> dict;
        dict[0] = " ";
        dict[1] = "";
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        vector<string> res;
        string entry;
        combine(digits, 0, entry, dict, res);
        return res;
    }
private:
    void combine(string &digits, int index, string &entry, unordered_map<int, string> &dict, vector<string> &res) {
        if (index == digits.size()) {
            res.push_back(entry);
            return;
        }
        for (int i = 0; i < dict[digits[index] - '0'].length(); ++i) {
            entry.push_back(dict[digits[index] - '0'][i]);
            combine(digits, index + 1, entry, dict, res);
            entry.pop_back();
        }
    }
};


// LinkedListCycle.cpp
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


// LinkedListCycleII.cpp
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


// LongestCommonPrefix.cpp
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if (strs.size() > 0) {
            for (int i = 0; i < strs[0].length(); ++i) {
                bool isPrefix = true;
                for (int j = 1; j < strs.size(); ++j) {
                    if (strs[j].length() < i + 1) {
                        isPrefix = false;
                        break;
                    }
                    if (strs[0][i] != strs[j][i]) {
                        isPrefix = false;
                        break;
                    }
                }
                if (isPrefix) {
                    prefix.push_back(strs[0][i]);
                } else {
                    break;
                }
            }
        }
        return prefix;
    }
};


// LongestConsecutiveSequence.cpp
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() > 0) {
            unordered_map<int, bool> m;
            for (int i = 0; i < num.size(); ++i) {
                m[num[i]] = false;
            }
            int res = 0;
            for (int i = 0; i < num.size(); ++i) {
                if (m[num[i]]) {
                    continue;
                }
                m[num[i]] = true;
                int len = 1;
                for (int j = num[i] + 1; m.find(j) != m.end(); ++j) {
                    ++len;
                    m[num[j]] = true;
                }
                for (int j = num[i] - 1; m.find(j) != m.end(); --j) {
                    ++len;
                    m[num[j]] = true;
                }
                res = max(res, len);
            }
            return res;
        }
        return 0;
    }
};

// more elegant solution
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> dict;
        for (int i = 0; i < num.size(); ++i) {
            dict[num[i]] = false;
        }
        int res = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (!dict[num[i]]) {
                int count = 1;
                int j = num[i];
                while(dict.find(++j) != dict.end()) {
                    dict[j] = true;
                    count++;
                }
                j = num[i];
                while(dict.find(--j) != dict.end()) {
                    dict[j] = true;
                    count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};

// alternative
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> dict;
        for (int i = 0; i < num.size(); ++i) {
            dict[num[i]] = i;
        }
        int res = 0;
        for (unordered_map<int, int>::iterator iter = dict.begin(); iter != dict.end(); ++iter) {
            int n = iter->first;
            int count = 0;
            if (dict[n] > - 1) {
                while(dict.find(n) != dict.end()) {
                    dict[n] = -1;
                    n++, count++;
                }
                n = iter->first - 1;
                while(dict.find(n) != dict.end()) {
                    dict[n] = -1;
                    n--, count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};


// LongestPalindromicSubstring.cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 1, start = 0;
        bool dp[1000][1000] = { false };
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

// alternative
class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1000][1000] = { false };
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
        }
        int start = 0, end = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                end = i + 1;
            }
        }
        for (int i = s.length() - 3; i >= 0; --i) {
            for (int j = i + 2; j < s.length(); ++j) {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if ((j - i) > (end - start)) {
                        start = i;
                        end = j;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// more elegant solution
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        bool dp[1000][1000] = { false };
        for (int i = s.length() - 1; i >= 0; --i) {
            for (int j = i; j < s.length(); ++j) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                    if (j - i > end - start) {
                        start = i;
                        end = j;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};


// LongestSubstringWithoutRepeatingCharacters.cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() > 0) {
            int len = 0, maxLen = 0;
            unordered_map<char, int> dict;
            for (int i = 0; i < s.length(); ++i, ++len) {
                if (dict.find(s[i]) != dict.end()) {
                    maxLen = max(len, maxLen);
                    len = 0;
                    i = dict[s[i]] + 1;
                    dict.clear();
                } else {
                    dict[s[i]] = i;
                }
            }
            return max(maxLen, len);
        }
        return 0;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dict;
        int res = 0, start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (dict.find(s[i]) != dict.end()) {
                removeDup(dict, start, dict[s[i]], s);
                start = dict[s[i]] + 1;
            }
            dict[s[i]] = i;
            res = max(res, i - start + 1);
        }
        return res;
    }
private:
    void removeDup(unordered_map<char, int> &dict, int start, int end, string &s) {
        for (int i = start; i < end; ++i) {
            dict.erase(s[i]);
        }
    }
};


// LongestValidParentheses.cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() > 0) {
            stack<pair<int, int> > stk;
            int len = 0, t = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] == '(') {
                    stk.push(make_pair(s[i], i));
                } else {
                    if (stk.empty()) {
                        t = i + 1;
                    } else {
                        pair<int, int> p = stk.top();
                        stk.pop();
                        if (p.first == '(') {
                            if (!stk.empty()) {
                                len = max(len, i - stk.top().second);
                            } else {
                                len = max(len, i - t + 1);
                            }
                        }
                    }
                }
            }
            return len;
        }
        return 0;
    }
};


// MaxPointsOnALine.cpp
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() > 0) {
            int maxNum = 0;
            unordered_map<double, int> slope;
            for (int i = 0; i < points.size(); ++i) {
                slope.clear();
                int samePoint = 1;
                for (int j = i + 1; j < points.size(); ++j) {
                    if (isSame(points[i], points[j])) {
                        samePoint++;
                    } else {
                        double s = getSlope(points[i], points[j]);
                        slope[s] += 1;
                    }
                }
                maxNum = max(maxNum, samePoint);
                for (unordered_map<double, int>::iterator iter = slope.begin(); iter != slope.end(); ++iter) {
                    maxNum = max(maxNum, samePoint + iter->second);
                }
            }
            return maxNum;
        }
        return 0;
    }
private:
    bool isSame(Point &p1, Point &p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
    double getSlope(Point &p1, Point &p2) {
        if (p1.x == p2.x) {
            return INT_MAX;
        }
        return (double) (p2.y - p1.y) / (double) (p2.x - p1.x);
    }
};


// MaximalRectangle.cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        int res = 0;
        vector<vector<int> > p(row, vector<int>(col));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    if (j == 0) {
                        p[i][j] = 1;
                    } else {
                        p[i][j] = p[i][j - 1] + 1;
                    }
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (p[i][j] != 0) {
                    int h = i - 1;
                    int tmp = p[i][j];
                    int mini = p[i][j];
                    while(h >= 0) {
                        if (p[h][j] == 0) {
                            break;
                        } else {
                            mini = min(mini, p[h][j]);
                            tmp = max(tmp, mini * (i - h + 1));
                        }
                        h--;
                    }
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};


// MaximumDepthofBinaryTree.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root) {
            if (root->left && root->right) {
                return 1 + max(maxDepth(root->left), maxDepth(root->right));
            } else if (root->left && !root->right) {
                return 1 + maxDepth(root->left);
            } else if (!root->left && root->right) {
                return 1 + maxDepth(root->right);
            } else {
                return 1;
            }
        }
        return 0;
    }
};

// more elegant solution
class Solution {
public:
    int maxDepth(TreeNode *root) {
        return depth(root);
    }
private:
    int depth(TreeNode *root) {
        if (root) {
            return 1 + max(depth(root->left), depth(root->right));
        }
        return 0;
    }
};


// MaximumSubarray.cpp
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int last = A[0];
        int max_sum = last;
        for (int i = 1; i < n; ++i) {
            if (last > 0) {
                last += A[i];
            } else {
                last = A[i];
            }
            max_sum = max(max_sum, last);
        }
        return max_sum;
    }
};


// MedianOfTwoSortedArrays.cpp
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int len = m + n;
        if (len & 0x01) {
            return findMedian(A, m, B, n, len / 2 + 1);
        } else {
            return (findMedian(A, m, B, n, len / 2) + findMedian(A, m, B, n, len / 2 + 1)) / 2;
        }
    }
private:
    double findMedian(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return findMedian(B, n, A, m, k);
        }
        if (m == 0) {
            return B[k - 1];
        }
        if (k == 1) {
            return min(A[0], B[0]);
        }
        int pa = min(k / 2, m);
        int pb = k - pa;
        if (A[pa - 1] < B[pb - 1]) {
            return findMedian(A + pa, m - pa, B, n, k - pa);
        }
        return findMedian(A, m, B + pb, n - pb, k - pb);
    }
};


// MergeIntervals.cpp
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        list<Interval> l;
        sort(intervals.begin(), intervals.end(), compare);
        l.assign(intervals.begin(), intervals.end());
        list<Interval>::iterator pre = l.begin();
        list<Interval>::iterator iter = l.begin();
        iter++;
        while(iter != l.end()) {
            if (iter->start <= pre->end) {
                pre->end = max(iter->end, pre->end);
                iter = l.erase(iter);
            } else {
                pre++, iter++;
            }
        }
        res.assign(l.begin(), l.end());
        return res;
    }
private:
    static int compare(Interval i1, Interval i2) {
        return i1.start < i2.start;
    }
};


// MergeKSortedLists.cpp
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


// MergeSortedArray.cpp
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int count = m + n - 1;
        m--, n--;
        while(m >= 0 && n >= 0) {
            A[count--] = A[m] >= B[n]? A[m--] : B[n--];
        }
        while(n >= 0) {
            A[count--] = B[n--];
        }
    }
};


// MergeTwoSortedLists.cpp
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        while(l1 || l2) {
            int val1 = l1? l1->val : INT_MAX;
            int val2 = l2? l2->val : INT_MAX;
            if (val1 <= val2) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};


// MinimumDepthOfBinaryTree.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root) {
            int depth = 1;
            return minDepth(root, depth);
        }
        return 0;
    }
private:
    int minDepth(TreeNode *root, int &depth) {
        if (root && !root->left && !root->right) {
            return depth;
        }
        int d = depth + 1;
        int leftDepth = INT_MAX;
        int rightDepth = INT_MAX;
        if (root->left) {
            leftDepth = minDepth(root->left, d);
        }
        if (root->right) {
            rightDepth = minDepth(root->right, d);
        }
        return min(leftDepth, rightDepth);
    }
};

// another solution
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root) {
            depth = INT_MAX;
            minDepth(root, 1);
            return depth;
        }
        return 0;
    }
private:
    int depth;
    void minDepth(TreeNode *root, int cur) {
        if (root) {
            if (!root->left && !root->right) {
                depth = min(depth, cur);
            }
            if (root->left) {
                minDepth(root->left, cur + 1);
            }
            if (root->right) {
                minDepth(root->right, cur + 1);
            }
        }
    }
};

// more elegant soltuion
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root) {
            if (!root->left && !root->right) {
                return 1;
            } else if (root->left && !root->right) {
                return 1 + minDepth(root->left);
            } else if (!root->left && root->right) {
                return 1 + minDepth(root->right);
            } else {
                return 1 + min(minDepth(root->left), minDepth(root->right));
            }
        }
        return 0;
    }
};


// MinimumPathSum.cpp
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 1; i < row; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < col; ++j) {
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[row - 1][col - 1];
    }
};


// MinimumWindowSubstring.cpp
class Solution {
public:
    string minWindow(string S, string T) {
        if (T.length() == 0 && S.length() == 0) {
            return "";
        }
        if (T.length() > S.length()) {
            return "";
        }
        int expect[256] = { 0 };
        int appear[256] = { 0 };
        int start = 0, minLength = INT_MAX, count = 0, end = 0, minStart = 0;
        for (int i = 0; i < T.length(); ++i) {
            expect[T[i]]++;
        }
        for (end = 0; end < S.length(); ++end) {
            if (expect[S[end]] > 0) {
                appear[S[end]]++;
                if (expect[S[end]] >= appear[S[end]]) {
                    count++;
                }
            }
            if (count == T.length()) {
                while(expect[S[start]] == 0 || appear[S[start]] > expect[S[start]]) {
                    appear[S[start]]--;
                    start++;
                }
                if (end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    minStart = start;
                }
            }
        }
        if (minLength == INT_MAX) {
            return "";
        }
        return S.substr(minStart, minLength);
    }
};


// MultiplyStrings.cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0) {
            return "";
        }
        bool pos = true;
        if (num1[0] == '-') {
            num1 = num1.substr(1);
            pos = !pos;
        }
        if (num2[0] == '-') {
            num2 = num2.substr(1);
            pos = !pos;
        }
        //main part
        string res = "0";
        for (int i = num2.size() - 1; i >= 0; i--) {
            string m = mpl(num1, num2[i]); // num1 multiply by num2[i]
            if (m != "0") {
                add(res, m, num2.size() - 1 - i); // add m to the result
            }
        }
        if (!pos) {
            res = "-" + res;
        }
        return res;
    }
private:
    string mpl(string num, char n) {
        string res;
        int carry = 0;
        if (n == '0') {
            return "0";
        }
        for (int i = num.size() - 1; i >= 0; i--) {
            int m = (num[i] - '0') * (n - '0') + carry;
            carry = m / 10;
            m = m % 10;
            res = char(m + '0') + res;
        }
        if (carry != 0) {
            res = char(carry + '0') + res;
        }
        return res;
    }
    void add(string &res, string m,int idx) {
        if (res == "") {
            res = m;
        } else {
            m = m + string(idx, '0');
            int carry = 0;
            int i = res.size() - 1;
            int j = m.size() - 1;
            while (i >= 0) {
                int k = (res[i] - '0') + (m[j] - '0') + carry;
                carry = k / 10;
                k= k % 10;
                res[i] = char(k + '0');
                i--;
                j--;
            }
            while (j >= 0) {
                if (carry > 0) {
                    int kk = (m[j] - '0') + carry;
                    carry = kk / 10;
                    kk = kk % 10;
                    res = char(kk + '0') + res;
                } else {
                    res = m[j] + res;
                }
                j--;
            }
            if (carry>0) {
                res = char(carry+'0') + res;
            }
        }
    }
};

// alternative
class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "0";
        for (int i = num2.size() - 1; i >= 0; --i) {
            string p = multiply(num1, num2[i]);
            if (p != "0") {
                for (int j = 0; j < num2.size() - i - 1; ++j) {
                    p += "0";
                }
                res = add(p, res);
            }
        }
        return res;
    }
private:
    string multiply(string &num, char c) {
        if (c == '0') {
            return "0";
        }
        string res;
        int carry = 0;
        for (int i = num.size() - 1; i >= 0; --i) {
            int m = (num[i] - '0') * (c - '0') + carry;
            res = char(m % 10 + '0') + res;
            carry = m / 10;
        }
        if (carry) {
            res = char(carry + '0') + res;
        }
        return res;
    }
    string add(string &a, string &b) {
        int carry = 0, i_a = a.length() - 1, i_b = b.length() - 1;
        string res;
        while(i_a >= 0 || i_b >= 0) {
            int val1 = i_a >= 0 ? a[i_a] - '0' : 0;
            int val2 = i_b >= 0 ? b[i_b] - '0' : 0;
            int sum = val1 + val2 + carry;
            char ch = sum % 10 + '0';
            carry = sum / 10;
            res.push_back(ch);
            i_a--, i_b--;
        }
        if (carry) {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// N-Queens.cpp
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return res;
    }
private:
    vector<vector<string> > res;
    void solve(vector<string> &board, int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            board[row][i] = 'Q';
            if (isValid(row, i, n, board)) {
                solve(board, row + 1, n);
            }
            board[row][i] = '.';
        }
    }
    bool isValid(int x, int y, int n, vector<string> &board) {
        for (int i = 0; i < x; ++i) {
            if (board[i][y] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};


// N-QueensII.cpp
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<char > > board(n, vector<char>(n, '.'));
        int res = 0;
        total(n, 0, board, res);
        return res;
    }
private:
    void total(int n, int row, vector<vector<char> > &board, int &res) {
        if (row == n) {
            res++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isValid(board, row, i, n)) {
                board[row][i] = 'Q';
                total(n, row + 1, board, res);
            }
            board[row][i] = '.';
        }
    }
    bool isValid(vector<vector<char> > &board, int x, int y, int n) {
        for (int i = x - 1; i >= 0; --i) {
            if (board[i][y] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};


// NextPermutation.cpp
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        next_permutation(num.begin(), num.end());
    }
};

/*
Step 1: Find the largest index k, such that A[k]<A[k+1]. If not exist, this is the last permutation.
    (in this problem just sort the vector and return.)
Step 2: Find the largest index l, such that A[l]>A[k].
Step 3: Swap A[k] and A[l].
Step 4: Reverse A[k+1] to the end.
*/
// detailed algorithm
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int index = -1;
        for (int i = 0; i < num.size() - 1; ++i) {
            if (num[i] < num[i + 1]) {
                index = i;
            }
        }
        if (index == -1) {
            sort(num.begin(), num.end());
            return;
        }
        for (int i = num.size() - 1; i >= 0; --i) {
            if (num[i] > num[index]) {
                swap(num[i], num[index]);
                break;
            }
        }
        reverse(num.begin() + index + 1, num.end());
    }
};

// alternative
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int index = -1;
        for (int i = num.size() - 2; i >= 0; --i) {
            if (num[i] < num[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            sort(num.begin(), num.end());
            return;
        }
        for (int i = num.size() - 1; i >= 0; --i) {
            if (num[i] > num[index]) {
                swap(num[i], num[index]);
                break;
            }
        }
        reverse(num.begin() + index + 1, num.end());
    }
};


// PalindromeNumber.cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int bit = log10(x);
        int p = pow(10, bit);
        int res = true;
        for (int i = 0; i < (bit + 1) / 2; ++i) {
            if (x % 10 != x / p) {
                res = false;
                break;
            } else {
                x -= x / p * p;
                x /= 10;
                p /= 100;
            }
        }
        return res;
    }
};

// shorter solution
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int p = pow(10, (int)log10(x));
        while(x > 0 && x / p == x % 10) {
            x -= x / p * p;
            x /= 10;
            p /= 100;
        }
        return x == 0;
    }
};

// PalindromePartitioning.cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.length() > 0) {
            vector<string> path;
            partition(s, 0, path);
        }
        return res;
    }
private:
    vector<vector<string> > res;
    bool isPalindrome(string &s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
    void partition(string &s, int start, vector<string> &cur) {
        if (start == s.length()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < s.length() - start; ++i) {
            string sub = s.substr(start, i + 1);
            if (isPalindrome(sub)) {
                cur.push_back(sub);
                partition(s, start + i + 1, cur);
                cur.pop_back();
            }
        }
    }
};


// PalindromePartitioningII.cpp
class Solution {
public:
    int minCut(string s) {
        if (s.length() > 0) {
            vector<vector<bool> > dict(s.length(), vector<bool>(s.length()));
            vector<int> res(s.length());
            for (int i = s.length() - 1; i >= 0; --i) {
                for (int j = i; j < s.length(); ++j) {
                    if (s[i] == s[j] && ((j - i < 2) || dict[i + 1][j - 1])) {
                        dict[i][j] = true;
                    }
                }
            }
            for (int i = 0; i < s.length(); ++i) {
                int cut = s.length();
                if (dict[0][i]) {
                    res[i] = 0;
                } else {
                    for (int j = 0; j < i; ++j) {
                        if (dict[j + 1][i] && cut > res[j] + 1) {
                            cut = res[j] + 1;
                        }
                    }
                    res[i] = cut;
                }
            }
            return res[s.length() - 1];
        }
        return 0;
    }
};


// PartitionList.cpp
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *p = new ListNode(0);
        p->next = head;
        head = p; // used to save the result head.
        ListNode *last = head; // used to get the last node
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            return head->next;
        }
        int n = 0; //length of the list
        while (last->next) {
            last = last->next;
            n++;
        } //get the length and last node
        while (n > 0) {  // in case  of non-stop loop, count n.
            if (p->next->val < x) {  // val<x keep the node
                p = p->next;
                n--;
            } else {                  // val>=x move to last
                last->next = new ListNode(p->next->val);    // add node to the last
                last = last->next;
                p->next = p->next->next;                    //delete current node
                n--;
            }
        }
        return head->next;  //the 1st node is elmininated 
    }
};


// PascalTriangle.cpp
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        for (int i = 0; i < numRows; ++i) {
            vector<int> entry;
            for (int j = 0; j < i + 1; ++j) {
                entry.push_back(pascal(i, j));
            }
            res.push_back(entry);
        }
        return res;
    }
private:
    map<pair<int, int>, int> memo;
    int pascal(int row, int col) {
        pair<int, int> p = make_pair(row, col);
        if (memo.find(p) != memo.end()) {
            return memo[p];
        }
        if (row == 0 || col == 0 || row == col) {
            return 1;
        } else {
            pair<int, int> p1 = make_pair(row - 1, col - 1);
            pair<int, int> p2 = make_pair(row - 1, col);
            memo[p] = pascal(row - 1, col - 1) + pascal(row - 1, col);
            return memo[p];
        }
    }
};

// normal solution
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res(numRows);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (j == 0 || j == i) {
                    res[i].push_back(1);
                } else {
                    res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
            }
        }
        return res;
    }
};


// PascalTriangleII.cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 0; i < rowIndex + 1; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                res.push_back(pascal(i, j));
            }
        }
        res.assign(res.end() - rowIndex - 1, res.end());
        return res;
    }
private:
    map<pair<int, int>, int> memo;
    int pascal(int row, int col) {
        pair<int, int> p = make_pair(row, col);
        if (memo.find(p) != memo.end()) {
            return memo[p];
        } else {
            if (row == 0 || col == 0 || row == col) {
                return 1;
            } else {
                memo[p] = pascal(row - 1, col - 1) + pascal(row - 1, col);
                return memo[p];
            }
        }
        return 0;
    }
};

// O(1) space
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res(numRows);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (j == 0 || j == i) {
                    res[i].push_back(1);
                } else {
                    res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
            }
        }
        return res;
    }
};


// PathSum.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root) {
            return hasPath(root, sum);
        }
        return false;
    }
private:
    bool hasPath(TreeNode *root, int sum) {
        if (root) {
            sum -= root->val;
            if (!root->left && !root->right && sum == 0) {
                return true;
            } else if (!root->left && !root->right && sum != 0) {
                return false;
            }
            return hasPath(root->left, sum) || hasPath(root->right, sum);
        }
        return false;
    }
};

// more elegant solution
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root) {
            if (sum == root->val && !root->left && !root->right) {
                return true;
            } else {
                return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
            }
        }
        return false;
    }
};


// PathSumII.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (root) {
            vector<int> path;
            pathSum(root, sum, path);
        }
        return res;
    }
private:
    vector<vector<int> > res;
    void pathSum(TreeNode *root, int sum, vector<int> &path) {
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val) {
            res.push_back(path);
            return;
        }
        if (root->left) {
            pathSum(root->left, sum - root->val, path);
            path.pop_back();
        }
        if (root->right) {
            pathSum(root->right, sum - root->val, path);
            path.pop_back();
        }
    }
};


// PermutationSequence.cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact = { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
        string res;
        for (int i = 0; i < n; ++i) {
            res.push_back(i + 1 + '0');
        }
        k--;
        for (int i = 0; i < n; ++i) {
            int m = k / fact[n - i - 1];
            int s = k % fact[n - i - 1];
            if (m == 0 && n == 0) {
                return res;
            } else {
                if (m > 0) {
                    for (int j = i + m - 1; j > i - 1; --j) {
                        swap(res[j], res[j - 1]);
                    }
                    if (s == 0) {
                        return res;
                    }
                }
            }
            k = s;
        }
        return res;
    }
};


// Permutations.cpp
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        do {
            res.push_back(num);
        } while(next_permutation(num.begin(), num.end()));
        return res;
    }
};


// PermutationsII.cpp
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        do {
            res.push_back(num);
        } while(next_permutation(num.begin(), num.end()));
        return res;
    }
};


// PlusOne.cpp
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        digits[digits.size() - 1] += 1;
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += carry;
            carry = digits[i] == 10? 1 : 0;
            res.push_back(digits[i] % 10);
        }
        if (carry) {
            res.push_back(1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// a little elegent
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1, i = digits.size() - 1;
        vector<int> res;
        while(i >= 0) {
            int sum = digits[i] + carry;
            carry = sum / 10;
            res.push_back(sum % 10);
            i--;
        }
        if (carry) {
            res.push_back(1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// PopulatingNextRightPointersInEachNode.cpp
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


// PopulatingNextRightPointersInEachNodeII.cpp
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


// Pow.cpp
class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        double result = pow(x, n / 2);
        if (n < 0 && n % 2 == 0) {
            return result * result;
        } else if (n < 0 && n % 2 == -1) {
            return result * result * 1 / x;
        } else if (n > 0 && n % 2 == 0) {
            return result * result;
        } else if (n > 0 && n % 2 == 1) {
            return result * result * x;
        }
    }
};

// more elegant solution
class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n & 0x01) {
            double p = pow(x, n / 2);
            if (n > 0) {
                return p * p * x;
            } else {
                return p * p * 1 / x;
            }
        }
        double p = pow(x, n / 2);
        return p * p;
    }
};


// RecoverBinarySearchTree.cpp
// O(n) space
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if (root) {
            traverse(root);
            sort(value.begin(), value.end());
            for (int i = 0; i < path.size(); ++i) {
                path[i]->val = value[i];
            }
        }
    }
private:
    vector<TreeNode *> path;
    vector<int> value;
    void traverse(TreeNode *root) {
        if (!root) {
            return;
        }
        traverse(root->left);
        path.push_back(root);
        value.push_back(root->val);
        traverse(root->right);
    }
};

// O(1) space
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if (root) {
            first = second = pre = NULL;
            traverse(root);
            swap(first->val, second->val);
        }
    }
private:
    TreeNode *first;
    TreeNode *second;
    TreeNode *pre;
    void traverse(TreeNode *root) {
        if (root) {
            traverse(root->left);
            if (pre && pre->val > root->val) {
                if (!first) {
                    first = pre;
                }
                second = root;
            }
            pre = root;
            traverse(root->right);
        }
    }
};


// RegularExpressionMatching.cpp
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') {
            return *s == '\0';
        }
        if (*(p + 1) != '*') {
            if (*p == *s || (*p == '.' && *s != '\0'))
                return isMatch(s + 1, p + 1);
            else {
                return false;
            }
        } else {
            while (*p == *s || (*p == '.' && *s != '\0')) {
                if (isMatch(s, p + 2)) {
                    return true;
                }
                s++;
            }
            return isMatch(s, p + 2);
        }
    }
};

// alternative
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s || !p) {
            return false;
        }
        if (*p == '\0') {
            return *s == '\0';
        }
        if (*(p + 1) != '*') {
            return ((*s == *p) || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
        }
        while ((*p == *s) || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p + 2)) {
                return true;
            }
            s++;
        }
        return isMatch(s, p + 2);
    }
};


// RemoveDuplicatesFromSortedArray.cpp
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n > 0) {
            int cur = 0;
            for (int i = 1; i < n; ++i) {
                if (A[i] != A[cur]) {
                    cur++;
                    A[cur] = A[i];
                }
            }
            return cur + 1;
        }
        return n;
    }
};


// RemoveDuplicatesFromSortedArrayII.cpp
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n > 0) {
            int cur = 0, count = 0;
            for (int i = 1; i < n; ++i) {
                if (A[cur] != A[i]) {
                    A[++cur] = A[i];
                    count = 0;
                } else if (A[cur] == A[i] && count < 1) {
                    A[++cur] = A[i];
                    count++;
                }
            }
            return cur + 1;
        }
        return n;
    }
};


// RemoveDuplicatesFromSortedList.cpp
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        if (head) {
            dummy.next = head;
            ListNode *cur = dummy.next;
            while(cur) {
                ListNode *p = cur->next;
                while(p && p->val == cur->val) {
                    p = p->next;
                }
                cur->next = p;
                cur = cur->next;
            }
        }
        return dummy.next;
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *cur = head;
        while(cur) {
            ListNode *p = cur->next;
            while(p && p->val == cur->val) {
                p = p->next;
            }
            cur->next = p;
            cur = cur->next;
        }
        return head;
    }
};


// RemoveDuplicatesFromSortedListII.cpp
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        head = pre;
        ListNode *p = head;
        while(p->next) {
            ListNode *p2 = p->next;
            while (p2->next && (p2->val == p2->next->val)) {
                p2 = p2->next;
            }
            if (p2 != p->next) {
                p->next = p2->next;
            } else {
                p = p->next;
            }
        }
        return head->next;
    }
};

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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *cur = &dummy;
        while(cur && cur->next) {
            ListNode *p = cur->next->next;
            bool dup = false;
            while(p && p->val == cur->next->val) {
                p = p->next;
                dup = true;
            }
            if (dup) {
                cur->next = p;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};


// RemoveElement.cpp
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int count = 0;
        for (int i = 0; i < n - count; ++i) {
            if (A[i] == elem) {
                for (int j = i + 1; j < n - count; ++j) {
                    A[j - 1] = A[j];
                }
                i--;
                count++;
            }
        }
        return n - count;
    }
};


// RemoveNthNodeFromEndOfList.cpp
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head) {
            ListNode *cur = head, *start = head;
            ListNode *pre = NULL;
            while(start && n--) start = start->next;
            while(cur && start) {
                pre = cur;
                cur = cur->next;
                start = start->next;
            }
            if (pre) {
                pre->next = cur->next;
            } else {
                return head->next;
            }
        }
        return head;
    }
};


// ReorderList.cpp
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
    void reorderList(ListNode *head) {
        if (!head) {
            return;
        }
        if (head->next == NULL) {
            return;
        }
        ListNode *p = head;
        ListNode *q = head;

        //find the midddle pointer
        while (q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        //now p is middle pointer
        //reverse p->next to end
        q = p->next;
        while (q->next) {
            ListNode* tmp = p->next;
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = tmp;
        }
        //reorder
        q = head;
        while (p != q && p->next) {
            ListNode *tmp = q->next;
            q->next = p->next;
            p->next = p->next->next;
            q->next->next = tmp;
            q = q->next->next;
        }
        return;
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
    void reorderList(ListNode *head) {
        if (!head) {
            return;
        }
        ListNode *l1 = head, *cur = head;
        ListNode *l2 = reverse(findMiddle(head));
        bool reversed = false;
        while(l1 || l2) {
            if (!reversed) {
                l1 = l1 ? l1->next : l1;
                cur->next = l2;
            } else {
                l2 = l2 ? l2->next : l2;
                cur->next = l1;
            }
            cur = cur->next;
            reversed = !reversed;
        }
    }
private:
    ListNode *findMiddle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *res = slow->next;
        slow->next = NULL;
        return res;
    }
    ListNode *reverse(ListNode *head) {
        ListNode *cur = head, *prev = NULL;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};


// RestoreIPAddresses.cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() > 3 && s.length() < 13) {
            string ip;
            restore(s, 0, ip, 0);
        }
        return res;
    }
private:
    vector<string> res;
    bool isValid(string &ip) {
        if (ip.length() == 1) {
            return ip[0] >= '0' && ip[0] <= '9';
        } else if (ip.length() == 2) {
            return ip[0] >= '1' && ip[0] <= '9';
        } else if (ip.length() == 3) {
            int n = atoi(&ip[0]);
            return ip[0] >= '1' && ip[0] <= '2' && n >= 100 && n <= 255;
        }
        return false;
    }
    void restore(string &s, int index, string &ip, int seg) {
        if (seg == 4) {
            if (index == s.length()) {
                res.push_back(ip.substr(0, ip.length() - 1));
            }
            return;
        }
        string pre = ip;
        for (int i = 0; i < 3 && i + index < s.length(); ++i) {
            if (s.length() - index > (4 - seg) * 3) {
                return;
            }
            string sub = s.substr(index, i + 1);
            if (isValid(sub)) {
                ip += sub + ".";
                restore(s, index + i + 1, ip, seg + 1);
                ip = pre;
            }
        }
    }
};


// ReverseInteger.cpp
class Solution {
public:
    int reverse(int x) {
        int sign = x > 0? 1: -1;
        int num = x * sign;
        int res = 0;
        while(num > 0) {
            int remain = num % 10;
            res = res * 10 + remain;
            num /= 10;
        }
        if (res < 0) {
            return -1;
        }
        return res * sign;
    }
};


// ReverseLinkedListII.cpp
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *h = head;
        for (int i = 0; i < n - m; i++) {
            int k1 = m + i;
            int k2 = n - i;
            if (k1 >= k2) {
                return head;
            }
            ListNode *p = h;
            ListNode *q = h;
            while (k1 - 1 > 0) {
                p = p->next;
                k1--;
            }
            while (k2 - 1 > 0) {
                q = q->next;
                k2--;
            }
            int tmp = p->val;
            p->val = q->val;
            q->val = tmp;
        }
        return head;
    }
};


// ReverseNodesInK-Group.cpp
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head) {
            return NULL;
        }
        ListNode* p = new ListNode(-1);
        p->next = head;
        head = p;
        ListNode* q = p;
        while (true) {
            int i = 0;
            while (q && i < k) {
                q = q->next;
                i++;
            }
            if (!q) {
                return head->next;
            } else {
                while (p->next != q) {
                    ListNode* d = p->next;
                    ListNode* l = q->next;
                    p->next = p->next->next;
                    q->next = d;
                    d->next = l;
                }
                for(int j = 0; j < k; j++) {
                    p = p->next;
                }
                q = p;
            }
        }
        return head->next;
    }
};


// ReverseWordsInAString.cpp
class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() > 0) {
            stack<const char *> stk;
            const char *token = strtok(&s[0], " ");
            while(token != NULL) {
                stk.push(token);
                token = strtok(NULL, " ");
            }
            string res;
            while(!stk.empty()) {
                res += string(stk.top()) + " ";
                stk.pop();
            }
            s = res.substr(0, res.length() - 1);
        }
    }
};


// RomanToInteger.cpp
class Solution {
public:
    int romanToInt(string s) {
        if (s.length() > 0) {
            int last = charToInt(s[0]);
            int num = last;
            for (int i = 1; i < s.length(); ++i) {
                int cur = charToInt(s[i]);
                if (cur > last) {
                    num += cur - 2 * last;
                } else {
                    num += cur;
                }
                last = cur;
            }
            return num;
        }
        return 0;
    }
private:
    int charToInt(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
};


// RotateImage.cpp
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > rotate(row, vector<int>(col));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                rotate[j][col - i - 1] = matrix[i][j];
            }
        }
        matrix = rotate;
    }
};

// in-place
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (row != 0) {
            int col = matrix[0].size();
            for (int i = 0; i < row - 1; ++i) {
                for (int j = 0; j < col - i - 1; ++j) {
                    swap(matrix[i][j], matrix[col - j - 1][row - i - 1]);
                }
            }
            for (int i = 0; i < row / 2; ++i) {
                for (int j = 0; j < col; ++j) {
                    swap(matrix[i][j], matrix[row - i - 1][j]);
                }
            }
        }
    }
};


// RotateList.cpp
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


// SameTree.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p != NULL && q != NULL && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
        } else if (p == NULL && q == NULL) {
            return true;
        } else {
            return false;
        }
    }
};


// ScrambleString.cpp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        int value1 = 0, value2 = 0;
        for (int i = 0; i < s1.length(); ++i) {
            value1 += s1[i] - 'a';
            value2 += s2[i] - 'a';
        }
        if (value1 != value2) {
            return false;
        }
        for (int i = 1; i < s1.length(); ++i) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) ||
                (isScramble(s1.substr(0, i), s2.substr(s2.length() - i)) &&
                isScramble(s1.substr(i), s2.substr(0, s2.length() - i)))) {
                    return true;
                }
        }
        return false;
    }
};


// SearchA2DMatrix.cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() > 0) {
            int row = matrix.size();
            int col = matrix[0].size();
            int i = 0, j = col - 1;
            while(i < row && j >= 0) {
                if (matrix[i][j] < target) {
                    i++;
                } else if (matrix[i][j] > target) {
                    j--;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};


// SearchForARange.cpp
// O(n) for worst case
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res = {-1, -1};
        if (A) {
            int low = 0, high = n - 1;
            int mid = 0;
            while(low <= high) {
                mid = (low + high) / 2;
                if (A[mid] < target) {
                    low = mid + 1;
                } else if (A[mid] > target) {
                    high = mid - 1;
                } else {
                    int index = mid;
                    while(index - 1 >= 0 && A[mid] == A[index - 1]) --index;
                    res[0] = index;
                    index = mid;
                    while(index + 1 < n && A[mid] == A[index + 1]) ++index;
                    res[1] = index;
                    break;
                }
            }
        }
        return res;
    }
};

// O(logn) for worst case
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        if (n > 0) {
            int low = 0, high = n;
            while(low < high) {
                int mid = (low + high) / 2;
                if (A[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            if (A[low] == target) {
                res[0] = low;
            } else {
                return res;
            }
            low = 0, high = n;
            while(low < high) {
                int mid = (low + high) / 2;
                if (A[mid] > target) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            res[1] = low - 1;
        }
        return res;
    }
};


// SearchInRotatedSortedArray.cpp
class Solution {
public:
    int search(int A[], int n, int target) {
        map<int, int> dict;
        for (int i = 0; i < n; ++i) {
            dict[A[i]] = i;
        }
        if (dict.find(target) != dict.end()) {
            return dict[target];
        }
        return -1;
    }
};

// space O(1)
class Solution {
public:
    int search(int A[], int n, int target) {
        if (A) {
            int low = 0, high = n - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if (A[mid] == target) {
                    return mid;
                } else if (A[mid] >= A[low]) {
                    if (target >= A[low] && target <= A[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    if (target >= A[low] || target <= A[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};


// SearchInRotatedSortedArrayII.cpp
class Solution {
public:
    bool search(int A[], int n, int target) {
        map<int, int> dict;
        for (int i = 0; i < n; ++i) {
            dict[A[i]] = i;
        }
        return dict.find(target) != dict.end();
    }
};

// space O(1)
class Solution {
public:
    bool search(int A[], int n, int target) {
        if (A) {
            int low = 0, high = n - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if (A[mid] == target) {
                    return true;
                } else if (A[mid] > A[low]) {
                    if (target >= A[low] && target < A[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else if (A[mid] < A[low]) {
                    if (target > A[mid] && target <= A[high]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                } else {
                    low++;
                }
            }
        }
        return false;
    }
};


// SearchInsertPosition.cpp
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if (mid > low && A[mid - 1] < target && A[mid] > target ) {
                return mid;
            } else if (A[mid] > target) {
                high = mid - 1;
            } else if (A[mid] < target) {
                low = mid + 1;
            } else if (A[mid] == target) {
                return mid;
            }
        }
        return low;
    }
};


// SetMatrixZeroes.cpp
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() > 0) {
            bool vertical = false, hori = false;
            for (int i = 0; i < matrix.size(); ++i) {
                if (matrix[i][0] == 0) {
                    vertical = true;
                    break;
                }
            }
            for (int i = 0; i < matrix[0].size(); ++i) {
                if (matrix[0][i] == 0) {
                    hori = true;
                    break;
                }
            }
            for (int i = 1; i < matrix.size(); ++i) {
                for (int j = 1; j < matrix[i].size(); ++j) {
                    if (matrix[i][j] == 0) {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
            for (int i = 1; i < matrix.size(); ++i) {
                for (int j = 1; j < matrix[0].size(); ++j) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
            if (vertical) {
                for (int i = 0; i < matrix.size(); ++i) {
                    matrix[i][0] = 0;
                }
            }
            if (hori) {
                for (int i = 0; i < matrix[0].size(); ++i) {
                    matrix[0][i] = 0;
                }
            }
        }
    }
};


// SimplifyPath.cpp
class Solution {
public:
    string simplifyPath(string path) {
        if (path.length() > 0) {
            char *token = strtok(&path[0], "/");
            stack<string> stk;
            while(token) {
                string s(token);
                if (s == ".." && !stk.empty()) {
                    stk.pop();
                } else if (s == ".") {
                    // do nothing
                } else if (s != ".." && s.length() > 0) {
                    stk.push(s);
                }
                token = strtok(NULL, "/");
            }
            string res;
            while(!stk.empty()) {
                res = "/" + stk.top() + res;
                stk.pop();
            }
            if (res.empty()) {
                return "/";
            }
            return res;
        }
        return string();
    }
};


// SingleNumber.cpp
class Solution {
public:
    int singleNumber(int A[], int n) {
        if (A && n > 0) {
            int ele = A[0];
            for (int i = 1; i < n; ++i) {
                ele ^= A[i];
            }
            return ele;
        }
        return -1;
    }
};


// SingleNumberII.cpp
class Solution {
public:
    int singleNumber(int A[], int n) {
        int count[sizeof(int) * 8] = { 0 };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < sizeof(int) * 8; ++j) {
                count[j] += A[i] >> j & 0x01;
                count[j] %= 3;
            }
        }
        int res = 0;
        for (int i = 0; i < sizeof(int) * 8; ++i) {
            res += count[i] << i;
        }
        return res;
    }
};


// SortColors.cpp
class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0, blue = n - 1, i = 0;
        while(i < blue + 1) {
            if (A[i] == 0) {
                swap(A[red], A[i]);
                i++, red++;
            } else if (A[i] == 1) {
                i++;
            } else if (A[i] == 2) {
                swap(A[i], A[blue]);
                blue--;
            }
        }
    }
};

// counting sort
class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3] = { 0 };
        for (int i = 0; i < n; ++i) {
            count[A[i]] += 1;
        }
        for (int i = 0; i < 3; ++i) {
            int start = 0;
            for (int j = 0; j < i; ++j) {
                start += count[j];
            }
            for (int k = 0; k < count[i]; ++k) {
                A[k + start] = i;
            }
        }
    }
};


// SortList.cpp
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
    ListNode *sortList(ListNode *head) {
        mergeSort(&head);
        return head;
    }
private:
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        while(l1 || l2) {
            int val1 = l1? l1->val : INT_MAX;
            int val2 = l2? l2->val : INT_MAX;
            if (val1 < val2) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
    void split(ListNode *head, ListNode **la, ListNode **lb) {
        ListNode *slow, *fast, *pre;
        if (!head || !head->next) {
            *la = head;
            *lb = NULL;
        } else {
            slow = fast = head;
            pre = NULL;
            while(fast && fast->next) {
                fast = fast->next->next;
                pre = slow;
                slow = slow->next;
            }
            *la = head;
            *lb = slow;
            pre->next = NULL;
        }
    }
    void mergeSort(ListNode **head) {
        ListNode *p = *head;
        if (p && p->next) {
            ListNode *left = NULL, *right = NULL;
            split(p, &left, &right);
            mergeSort(&left);
            mergeSort(&right);
            *head = merge(left, right);
        }
    }
};


// SpiralMatrix.cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int row = matrix.size();
        int col;
        if (row > 0) {
            col = matrix[0].size();
            vector<vector<int> > visited(row, vector<int>(col, 0));
            res.push_back(matrix[0][0]);
            visited[0][0] = 1;
            int i = 0, x = 0, y = 0;
            while(i < row * col - 1) {
                while(y + 1 < col && visited[x][y + 1] == 0) {
                    y++;
                    i++;
                    res.push_back(matrix[x][y]);
                    visited[x][y] = 1;
                }
                while(x + 1 < row && visited[x + 1][y] == 0) {
                    x++;
                    i++;
                    res.push_back(matrix[x][y]);
                    visited[x][y] = 1;
                }
                while(y - 1 >= 0 && visited[x][y - 1] == 0) {
                    y--;
                    i++;
                    res.push_back(matrix[x][y]);
                    visited[x][y] = 1;
                }
                while(x - 1 >= 0 && visited[x - 1][y] == 0) {
                    x--;
                    i++;
                    res.push_back(matrix[x][y]);
                    visited[x][y] = 1;
                }
            }
        }
        return res;
    }
};

// more elegant solution
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int row = matrix.size();
        if (row == 0) {
            return res;
        }
        int col = matrix[0].size();
        int start = 0;
        vector<vector<int> > visited(row, vector<int>(col, 0));
        while(row > start * 2 && col > start * 2) {
            int endRow = row - 1 - start;
            int endCol = col - 1 - start;
            for (int i = start; i < endCol + 1 && !visited[start][i]; ++i) {
                res.push_back(matrix[start][i]);
                visited[start][i] = 1;
            }
            for (int i = start + 1; i < endRow + 1 && !visited[i][endCol]; ++i) {
                res.push_back(matrix[i][endCol]);
                visited[i][endCol] = 1;
            }
            for (int i = endCol - 1; i >= start && !visited[endRow][i]; --i) {
                res.push_back(matrix[endRow][i]);
                visited[endRow][i] = 1;
            }
            for (int i = endRow - 1; i > start && !visited[i][start]; --i) {
                res.push_back(matrix[i][start]);
                visited[i][start] = 1;
            }
            start++;
        }
        return res;
    }
};


// SpiralMatrixII.cpp
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        if (n > 0) {
            int i = 1, x = 0, y = 0;
            matrix[0][0] = i++;
            while(i <= n * n) {
                while(y + 1 < n && matrix[x][y + 1] == 0) {
                    matrix[x][++y] = i++;
                }
                while(x + 1 < n && matrix[x + 1][y] == 0) {
                    matrix[++x][y] = i++;
                }
                while(y - 1 >= 0 && matrix[x][y - 1] == 0) {
                    matrix[x][--y] = i++;
                }
                while(x - 1 >= 0 && matrix[x - 1][y] == 0) {
                    matrix[--x][y] = i++;
                }
            }
        }
        return matrix;
    }
};

// more tuitive solution
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));
        int start = 0, col = n, row = n, count = 1;
        while(col > start * 2 && row > start * 2) {
            int endCol = col - 1 - start;
            int endRow = row - 1 - start;
            for (int i = start; i < endCol + 1; ++i) {
                res[start][i] = count;
                count++;
            }
            for (int i = start + 1; i < endRow + 1; ++i) {
                res[i][endCol] = count;
                count++;
            }
            for (int i = endCol - 1; i >= start; --i) {
                res[endRow][i] = count;
                count++;
            }
            for (int i = endRow - 1; i > start; --i) {
                res[i][start] = count;
                count++;
            }
            start++;
        }
        return res;
    }
};


// Sqrt.cpp
// binary search
class Solution {
public:
    int sqrt(int x) {
        if (x == 0) {
            return 0;
        }
        if (x == 1) {
            return 1;
        }
        long long low = 0, high = x;
        while(low + 1 < high) {
            long long mid = (low + high) / 2;
            if (mid * mid < x) {
                low = mid;
            } else if (mid * mid > x) {
                high = mid;
            } else {
                return mid;
            }
        }
        return low;
    }
};

// Newton-Raphson method
class Solution {
public:
    int sqrt(int x) {
        if (x < 0) return -1;
        double x0 = 1;
        double x1;
        while(1) {
            x1 = (x0 + x / x0) / 2;
            if (abs(x1 - x0) < 1) {
                return x1;
            }
            x0 = x1;
        }
    }
};


// StringToInteger.cpp
class Solution {
public:
    int atoi(const char *str) {
        if (str) {
            int i = 0, sign = 1, res = 0;
            while(str[i] == ' ') {
                i++;
            }
            if (str[i] == '+') {
                sign = 1;
                i++;
            } else if (str[i] == '-') {
                sign = -1;
                i++;
            }
            if (!isdigit(str[i])) {
                return 0;
            }
            while(isdigit(str[i])) {
                if (sign > 0 && res > INT_MAX / 10) {
                    return INT_MAX;
                }
                if (sign > 0 && res == INT_MAX / 10 && str[i] - '0' >= 7) {
                    return INT_MAX;
                }
                if (sign < 0 && -res < INT_MIN / 10) {
                    return INT_MIN;
                }
                if (sign < 0 && -res == INT_MIN / 10 && str[i] - '0' >= 8) {
                    return INT_MIN;
                }
                res = res * 10 + str[i] - '0';
                i++;
            }
            return res * sign;
        }
        return 0;
    }
};


// Subsets.cpp
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> sub;
        subset(S, 0, sub);
        return res;
    }
private:
    vector<vector<int> > res;
    void subset(vector<int> &S, int index, vector<int> &sub) {
        if (index == S.size()) {
            res.push_back(sub);
            return;
        }
        sub.push_back(S[index]);
        subset(S, index + 1, sub);
        sub.pop_back();
        subset(S, index + 1, sub);
    }
};


// SubsetsII.cpp
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> sub;
        subset(S, 0, sub);
        vector<vector<int> > rt;
        rt.assign(res.begin(), res.end());
        return rt;
    }
private:
    set<vector<int> > res;
    void subset(vector<int> &S, int index, vector<int> &sub) {
        if (index == S.size()) {
            res.insert(sub);
            return;
        }
        sub.push_back(S[index]);
        subset(S, index + 1, sub);
        sub.pop_back();
        subset(S, index + 1, sub);
    }
};


// SubstringWithConcatenationOfAllWords.cpp
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        int num = L.size();
        int len = L[0].size();
        if (num == 0) {
            return res;
        }
        unordered_map<string, int> dict;
        for (int i = 0; i < num; ++i) {
            dict[L[i]] += 1;
        }
        int i = 0;
        while ((i + num * len - 1) < S.size()) {
            unordered_map<string, int> selected;
            int j = 0;
            while (j < num) {
                string subs = S.substr(i + j * len, len);
                if (dict.find(subs) == dict.end()){
                    break;
                } else {
                    selected[subs]++;
                    if (selected[subs] > dict[subs]) {
                        break;
                    }
                    j++;
                }
            }
            if (j == num) {
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};


// SudokuSolver.cpp
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0);
    }
private:
    bool isValid(vector<vector<char> > &board, int x, int y) {
        char ch = board[x][y];
        for (int i = 0; i < 9; ++i) {
            if (y != i && ch == board[x][i]) {
                return false;
            }
            if (x != i && ch == board[i][y]) {
                return false;
            }
        }
        int m = x / 3 * 3;
        int n = y / 3 * 3;
        for (int i = m; i < m + 3; ++i) {
            for (int j = n; j < n + 3; ++j) {
                if (x != i && y != j && ch == board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char> > &board, int index) {
        if (index == 81) {
            return true;
        }
        int row = index / 9;
        int col = index % 9;
        if (board[row][col] == '.') {
            for (int k = 1; k < 10; ++k) {
                board[row][col] = k + '0';
                if (isValid(board, row, col) && solve(board, index + 1)) {
                    return true;
                }
            }
            board[row][col] = '.';
            return false;
        } else {
            return solve(board, index + 1);
        }
    }
};


// SumRootToLeafNumbers.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return traversal(root, 0);
    }
private:
    int traversal(TreeNode *root, int sum) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 10 * sum + root->val;
        }
        return traversal(root->left, sum * 10 + root->val) + traversal(root->right, sum * 10 + root->val);
    }
};

// another solution
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        sumToLeaf(root, 0);
        return res;
    }
private:
    int res;
    void sumToLeaf(TreeNode *root, int sum) {
        if (root) {
            if (!root->left && !root->right) {
                res += sum * 10 + root->val;
            }
            if (root->left) {
                sumToLeaf(root->left, sum * 10 + root->val);
            }
            if (root->right) {
                sumToLeaf(root->right, sum * 10 + root->val);
            }
        }
    }
};


// SurroundedRegions.cpp
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() > 0) {
            int row = board.size();
            int col = board[0].size();
            queue<pair<int, int> > q1;
            for (int i = 0; i < row; ++i) {
                if (board[i][0] == 'O') {
                    q1.push(make_pair(i, 0));
                }
                if (board[i][col - 1] == 'O') {
                    q1.push(make_pair(i, col - 1));
                }
            }
            for (int i = 0; i < col; ++i) {
                if (board[0][i] == 'O') {
                    q1.push(make_pair(0, i));
                }
                if (board[row - 1][i] == 'O') {
                    q1.push(make_pair(row - 1, i));
                }
            }
            while(!q1.empty()) {
                pair<int, int> node = q1.front();
                q1.pop();
                int x = node.first;
                int y = node.second;
                board[x][y] = '*';
                if (y - 1 >= 0 && board[x][y - 1] == 'O') {
                    q1.push(make_pair(x, y - 1));
                }
                if (y + 1 < col && board[x][y + 1] == 'O') {
                    q1.push(make_pair(x, y + 1));
                }
                if (x + 1 < row && board[x+ 1][y] == 'O') {
                    q1.push(make_pair(x + 1, y));
                }
                if (x - 1 >= 0 && board[x - 1][y] == 'O') {
                    q1.push(make_pair(x - 1, y));
                }
            }
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (board[i][j] == 'O') {
                        board[i][j] = 'X';
                    } else if (board[i][j] == '*') {
                        board[i][j] = 'O';
                    }
                }
            }
        }
    }
};


// SwapNodesInPairs.cpp
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
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(-1);
        ListNode *pre = &dummy;
        pre->next = head;
        ListNode *cur = head;
        while(cur && cur->next) {
            ListNode *tmp = cur->next->next;
            pre->next = cur->next;
            cur->next->next = cur;
            pre = cur;
            cur->next = tmp;
            cur = cur->next;
        }
        return dummy.next;
    }
};


// SymmetricTree.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root) {
            return isSymmetric(root->left, root->right);
        }
        return true;
    }
private:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if ((left != NULL && right == NULL) || (left == NULL && right != NULL)) {
            return false;
        }
        if (left && right && (left->val != right->val)) {
            return false;
        } else if (left && right && (left->val == right->val)) {
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }
        return true;
    }
};

// BFS
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root) {
            return traversal(root);
        }
        return true;
    }
private:
    bool traversal(TreeNode *root) {
        queue<TreeNode *> q1, q2;
        q1.push(root);
        while(!q1.empty()) {
            vector<TreeNode *> level;
            while(!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                level.push_back(node);
                if (node) {
                    q2.push(node->left);
                    q2.push(node->right);
                }
            }
            swap(q1, q2);
            if (!isSymmetric(level)) {
                return false;
            }
        }
        return true;
    }
    bool isSymmetric(vector<TreeNode *> &level) {
        int start = 0, end = level.size() - 1;
        while(start < end) {
            if (level[start] && !level[end] || !level[start] && level[end]) {
                return false;
            }
            if (level[start] && level[end] && (level[start]->val != level[end]->val)) {
                return false;
            }
            start++, end--;
        }
        return true;
    }
};

// iterative
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root) {
            queue<TreeNode *> q;
            q.push(root->left);
            q.push(root->right);
            while(!q.empty()) {
                TreeNode *node1 = q.front();
                q.pop();
                TreeNode *node2 = q.front();
                q.pop();
                if ((!node1 && node2) || (node1 && !node2)) {
                    return false;
                } else if (node1 && node2 && node1->val != node2->val) {
                    return false;
                }
                if ((node1 && node2 && node1->val == node2->val)) {
                    q.push(node1->left);
                    q.push(node2->right);
                    q.push(node1->right);
                    q.push(node2->left);
                }
            }
        }
        return true;
    }
};


// TextJustification.cpp
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        const int n = words.size();
        int begin = 0, len = 0;
        for (int i = 0; i < n; ++i) {
            if (len + words[i].size() + (i - begin) > L) {
                result.push_back(connect(words, begin, i - 1, len, L, false));
                begin = i;
                len = 0;
            }
            len += words[i].size();
        }
        result.push_back(connect(words, begin, n - 1, len, L, true));
        return result;
    }
private:
    string connect(vector<string> &words, int begin, int end, int len, int L, bool is_last) {
        string s;
        int n = end - begin + 1;
        for (int i = 0; i < n; ++i) {
            s += words[begin + i];
            addSpaces(s, i, n - 1, L - len, is_last);
        }
        if (s.size() < L) s.append(L - s.size(), ' ');
        return s;
    }
    void addSpaces(string &s, int i, int n, int L, bool is_last) {
        if (n < 1 || i > n - 1) return;
        int spaces = is_last ? 1 : (L / n + (i < (L % n) ? 1 : 0));
        s.append(spaces, ' ');
    }
};


// TrappingRainWater.cpp
// run time O(n) space O(n)
class Solution {
public:
    int trap(int A[], int n) {
        if (A && n > 2) {
            vector<int> left(n);
            vector<int> right(n);
            left[0] = 0;
            for (int i = 1; i < n; ++i) {
                left[i] = max(left[i - 1], A[i - 1]);
            }
            right[n - 1] = 0;
            for (int i = n - 2; i >= 0; --i) {
                right[i] = max(right[i + 1], A[i + 1]);
            }
            int res = 0;
            for (int i = 0; i < n; ++i) {
                if (A[i] < min(left[i], right[i])) {
                    res += min(left[i], right[i]) - A[i];
                }
            }
            return res;
        }
        return 0;
    }
};

// run time O(n) space O(1)
class Solution {
public:
    int trap(int A[], int n) {
        if (n > 1) {
            int maxIndex = 0;
            for (int i = 1; i < n; ++i) {
                if (A[maxIndex] < A[i]) {
                    maxIndex = i;
                }
            }
            int maxValue = 0;
            int res = 0;
            for (int i = 0; i < maxIndex; ++i) {
                if (A[i] < maxValue) {
                    res += maxValue - A[i];
                } else {
                    maxValue = A[i];
                }
            }
            maxValue = 0;
            for (int i = n - 1; i > maxIndex; --i) {
                if (A[i] < maxValue) {
                    res += maxValue - A[i];
                } else {
                    maxValue = A[i];
                }
            }
            return res;
        }
        return 0;
    }
};

// one round scan
class Solution {
public:
    int trap(int A[], int n) {
        if (A) {
            int left = 0, right = n - 1, res = 0, leftMax = 0, rightMax = 0;
            while(left <= right) {
                if (leftMax < rightMax) {
                    leftMax = max(A[left], leftMax);
                    if (A[left] < leftMax) {
                        res += leftMax - A[left];
                    }
                    left++;
                } else {
                    rightMax = max(A[right], rightMax);
                    if (A[right] < rightMax) {
                        res += rightMax - A[right];
                    }
                    right--;
                }
            }
            return res;
        }
        return 0;
    }
};


// Triangle.cpp
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};


// TwoSum.cpp
// Sort solution
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int, int> > num;
        for (int i = 0; i < numbers.size(); ++i) {
            num.push_back(make_pair(i, numbers[i]));
        }
        sort(num.begin(), num.end(), compare);
        int start = 0, end = num.size() - 1, sum = 0;
        vector<int> res;
        while(start < end) {
            sum = num[start].second + num[end].second;
            if (sum > target) {
                end--;
            } else if (sum < target) {
                start++;
            } else if (sum == target) {
                res.push_back(num[start].first + 1);
                res.push_back(num[end].first + 1);
                break;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
private:
    static int compare(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }
};

// Hash map solution
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < numbers.size(); ++i) {
            m[numbers[i]] = i + 1;
        }
        vector<int> res;
        for (int i = 0; i < numbers.size(); ++i) {
            int index = m[target - numbers[i]];
            if (index > 0 && index != (i + 1)) {
                res.push_back(i + 1);
                res.push_back(m[target - numbers[i]]);
                break;
            }
        }
        return res;
    }
};


// UniqueBinarySearchTrees.cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> count(n + 1, 0);
        count[0] = 1;
        count[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                count[i] += count[j] * count[i - j - 1];
            }
        }
        return count[n];
    }
};


// UniqueBinarySearchTreesII.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> res;
        generate(1, n, res);
        return res;
    }
private:
    void generate(int start, int end, vector<TreeNode *> &path) {
        if (start > end) {
            path.push_back(NULL);
            return;
        }
        for (int i = start; i < end + 1; ++i) {
            vector<TreeNode *> left;
            generate(start, i - 1, left);
            vector<TreeNode *> right;
            generate(i + 1, end, right);
            for (int li = 0; li < left.size(); ++li) {
                for (int ri = 0; ri < right.size(); ++ri) {
                    TreeNode *node = new TreeNode(i);
                    node->left = left[li];
                    node->right = right[ri];
                    path.push_back(node);
                }
            }
        }
    }
};


// UniquePaths.cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > d(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            d[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            d[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                d[i][j] += d[i - 1][j] + d[i][j - 1];
            }
        }
        return d[m - 1][n - 1];
    }
};


// UniquePathsII.cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int> > d(row, vector<int>(col));
        if (obstacleGrid[0][0] == 1) {
            d[0][0] = 0;
        } else {
            d[0][0] = 1;
        }
        for (int i = 1; i < row; ++i) {
            if (obstacleGrid[i][0] != 1) {
                d[i][0] += d[i - 1][0];
            }
        }
        for (int j = 1; j < col; ++j) {
            if (obstacleGrid[0][j] != 1) {
                d[0][j] += d[0][j - 1];
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    d[i][j] = 0;
                } else {
                    d[i][j] += d[i - 1][j] + d[i][j - 1];
                }
            }
        }
        return d[row - 1][col - 1];
    }
};


// ValidNumber.cpp
class Solution {
public:
    bool isNumber(const char *s) {
        char *end = NULL;
        strtod(s, &end);
        if (end == s) {
            return false;
        }
        while(*end) {
            if (*end != ' ') {
                return false;
            }
            end++;
        }
        return true;
    }
};

// alternative
class Solution {
public:
    bool isNumber(const char *s) {
        if (!s) {
            return false;
        }
        while(isspace(*s)) {
            s++;
        }
        if (*s == '+' || *s == '-') {
            s++;
        }
        bool hasExp = false, hasDot = false, firstPart = false, secondPart = false, hasSpace = false;
        while (*s != '\0') {
            if (*s == '.') {
                if (hasExp || hasDot || hasSpace) {
                    return false;
                } else {
                    hasDot = true;
                }
            } else if (*s == 'E' || *s == 'e') {
                if (hasExp || !firstPart || hasSpace) {
                    return false;
                } else {
                    hasExp = true;
                }
            } else if (isdigit(*s)) {
                if (hasSpace) {
                    return false;
                }
                if (!hasExp) {
                    firstPart = true;
                } else {
                    secondPart = true;
                }
            } else if (*s == '+' || *s == '-') {
                if (hasSpace) {
                    return false;
                }
                if (!hasExp || !(*(s - 1) == 'e' || *(s - 1) == 'E')) {
                    return false;
                }
            } else if (isspace(*s)) {
                hasSpace = true;
            } else {
                return false;
            }
            s++;
        }
        if (!firstPart) {
            return false;
        } else if (hasExp && !secondPart) {
            return false;
        }
        return true;
    }
};


// ValidPalindrome.cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() > 0) {
            int start = 0, end = s.length() - 1;
            bool res = true;
            while(start < end) {
                if (isalnum(s[start]) && isalnum(s[end])) {
                    if (tolower(s[start]) == tolower(s[end])) {
                        start++, end--;
                    } else {
                        res = false;
                        break;
                    }
                } else if (!isalnum(s[start]) && isalnum(s[end])) {
                    start++;
                } else if (isalnum(s[start]) && !isalnum(s[end])) {
                    end--;
                } else if (!isalnum(s[start]) && !isalnum(s[end])) {
                    start++, end--;
                }
            }
            return res;
        }
        return true;
    }
};


// ValidParentheses.cpp
class Solution {
public:
    bool isValid(string s) {
        if (s.length() > 0) {
            stack<char> stk;
            for (int i = 0; i < s.length(); ++i) {
                char ch = s[i];
                switch(ch) {
                case '(':
                case '{':
                case '[':
                    stk.push(ch);
                    break;
                case ')':
                    if (stk.size() == 0) return false;
                    if (stk.top() == '(') stk.pop();
                    else stk.push(ch);
                    break;
                case '}':
                    if (stk.size() == 0) return false;
                    if (stk.top() == '{') stk.pop();
                    else stk.push(ch);
                    break;
                case ']':
                    if (stk.size() == 0) return false;
                    if (stk.top() == '[') stk.pop();
                    else stk.push(ch);
                    break;
                }
            }
            return stk.size() == 0;
        }
        return true;;
    }
};


// ValidSudoku.cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() > 0) {
            unordered_set<char> row, col, block;
            for (int i = 0; i < 9; ++i) {
                row.clear();
                col.clear();
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] != '.') {
                        if (row.find(board[i][j]) != row.end()) {
                            return false;
                        } else {
                            row.insert(board[i][j]);
                        }
                    }
                    if (board[j][i] != '.') {
                        if (col.find(board[j][i]) != col.end()) {
                            return false;
                        } else {
                            col.insert(board[j][i]);
                        }
                    }
                }
            }
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    block.clear();
                    for (int m = 0; m < 3; ++m) {
                        for (int n = 0; n < 3; ++n) {
                            int x = m + i * 3;
                            int y = n + j * 3;
                            if (board[x][y] != '.') {
                                if (block.find(board[x][y]) != block.end()) {
                                    return false;
                                } else {
                                    block.insert(board[x][y]);
                                }
                            }
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }
};


// ValidateBinarySearchTree.cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// in order traverse
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        traverse(root);
        for (int i = 1; i < res.size(); ++i) {
            if (res[i] <= res[i - 1]) {
                return false;
            }
        }
        return true;
    }
private:
    vector<int> res;
    void traverse(TreeNode *root) {
        if (!root) {
            return;
        }
        traverse(root->left);
        res.push_back(root->val);
        traverse(root->right);
    }
};

// dfs
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
private:
    bool isValid(TreeNode *root, int low, int high) {
        if (!root) {
            return true;
        }
        return root->val > low && root->val < high && isValid(root->left, low, root->val) && isValid(root->right, root->val, high);
    }
};


// WildcardMatching.cpp
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *ss = s, *star = NULL;
        while(*s) {
            if ((*p == '?') || (*s == *p)) {
                s++, p++;
                continue;
            }
            if (*p == '*') {
                star = p++;
                ss = s;
                continue;
            }
            if (star) {
                p = star + 1;
                s = ++ss;
                continue;
            }
            return false;
        }
        while(*p == '*') {
            p++;
        }
        return !*p;
    }
};


// WordBreak.cpp
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.length() > 0) {
            vector<int> dp(s.length() + 1);
            dp[0] = 1;
            for (int i = 1; i < dp.size(); ++i) {
                for (int j = i - 1; j >= 0; --j) {
                    if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            return dp[s.length()];
        }
        return dict.find(s) != dict.end();
    }
};


// WordBreakII.cpp
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<bool> > p(s.length(), vector<bool>(s.length()));
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                string str = s.substr(i, j - i + 1);
                if (dict.find(str) != dict.end()) {
                    p[i][j] = true;
                }
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            if (p[i][s.length() - 1]) {
                string path;
                wordBreak(s, 0, path, dict, p);
                break;
            }
        }
        return res;
    }
private:
    vector<string> res;
    void wordBreak(string &s, int start, string &path, unordered_set<string> &dict, vector<vector<bool> > &p) {
        if (start == s.length()) {
            res.push_back(path.substr(0, path.length() - 1));
            return;
        }
        string prev = path;
        for (int i = 0; i < s.length(); ++i) {
            if (p[start][i]) {
                path += s.substr(start, i - start + 1) + " ";
                wordBreak(s, i + 1, path, dict, p);
                path = prev;
            }
        }
    }
};


// WordLadder.cpp
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q1, q2;
        q1.push(start);
        int level = 1;
        unordered_set<string> visited;
        while(!q1.empty()) {
            while(!q1.empty()) {
                string node = q1.front();
                q1.pop();
                for (int i = 0; i < node.length(); ++i) {
                    string str = node;
                    for (int j = 0; j < 26; ++j) {
                        str[i] = j + 'a';
                        if (str == end) {
                            return level + 1;
                        } else if (str != node && visited.find(str) == visited.end() && dict.find(str) != dict.end()) {
                            q2.push(str);
                            visited.insert(str);
                        }
                    }
                }
            }
            level++;
            swap(q1, q2);
        }
        return 0;
    }
};


// WordLadderII.cpp
class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        queue<string> q1, q2;
        q1.push(start);
        while(!q1.empty()) {
            while(!q1.empty()) {
                string node = q1.front();
                q1.pop();
                if (node == end) {
                    path.push_back(start);
                    buildPath(start, end);
                    return res;
                }
                vector<string> level = findPath(node, dict);
                if (level.size() > 0) {
                    mp[node] = level;
                }
                for (vector<string>::iterator iter = level.begin(); iter != level.end(); ++iter) {
                    if (visited.find(*iter) == visited.end()) {
                        q2.push(*iter);
                    }
                }
            }
            swap(q1, q2);
        }
        return res;
    }
private:
    unordered_set<string> visited;
    unordered_map<string, vector<string> > mp;
    vector<vector<string> > res;
    vector<string> path;

    vector<string> findPath(string &node, unordered_set<string> &dict) {
        vector<string> res;
        visited.insert(node);
        for (int i = 0; i < node.length(); ++i) {
            string str = node;
            for (int j = 0; j < 26; ++j) {
                str[i] = j + 'a';
                if (str != node && visited.find(str) == visited.end() && dict.find(str) != dict.end()) {
                    res.push_back(str);
                }
            }
        }
        return res;
    }
    void buildPath(string &start, string &end) {
        if (start == end) {
            res.push_back(path);
        } else {
            for (int i = 0; i < mp[start].size(); ++i) {
                path.push_back(mp[start][i]);
                buildPath(mp[start][i], end);
                path.pop_back();
            }
        }
    }
};


// WordSearch.cpp
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() > 0) {
            vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size()));
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[i].size(); ++j) {
                    if (find(board, i, j, 0, word, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    bool find(vector<vector<char> > &board, int x, int y, int index, string &word, vector<vector<bool> > &visited) {
        int row = board.size();
        int col = board[0].size();
        if (index == word.length()) {
            return true;
        }
        if (x < 0 || x >= row || y < 0 || y >= col) {
            return false;
        }
        if (visited[x][y]) {
            return false;
        }
        visited[x][y] = true;
        bool res = false;
        if (board[x][y] == word[index]) {
            res = find(board, x - 1, y, index + 1, word, visited) ||
                  find(board, x + 1, y, index + 1, word, visited) ||
                  find(board, x, y - 1, index + 1, word, visited) ||
                  find(board, x, y + 1, index + 1, word, visited);
        }
        visited[x][y] = false;
        return res;
    }
};


// ZigZagConversion.cpp
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows > 1) {
            vector<string> m(nRows);
            int i = 0, row = 0;
            bool isZigzag = false;
            while(i < s.length()) {
                if (row < nRows && !isZigzag) {
                    m[row] += s[i];
                    row++;
                    i++;
                } else {
                    if (!isZigzag) {
                        isZigzag = true;
                        row--;
                    } else {
                        row--;
                        m[row] += s[i];
                        i++;
                        if (row == 0) {
                            isZigzag = false;
                            row++;
                        }
                    }
                }
            }
            string res;
            for (int i = 0; i < m.size(); ++i) {
                for (int j = 0; j < m[i].length(); ++j) {
                    res += m[i][j];
                }
            }
            return res;
        }
        return s;
    }
};


