typedef struct MyTreeNode {
public:
    int begin;
    int end;
    int sum;
    MyTreeNode* left;
    MyTreeNode* right;
    MyTreeNode(int _begin, int _end, int _sum)
    : begin(_begin), end(_end), sum(_sum)
    {}
} MyTreeNode;

class NumArray {
private:
    vector<int> _nums;
    MyTreeNode* root;
    MyTreeNode* construct(int begin, int end, vector<int>& nums) {
        if (begin > end) {
            return nullptr;
        }
        MyTreeNode* root = new MyTreeNode(begin, end, 0);
        if (begin == end) {
            root->sum = nums[begin];
        } else {
            int mid = begin + (end - begin) / 2;
            root->left = construct(begin, mid, nums);
            root->right = construct(mid + 1, end, nums);
            root->sum = root->left->sum + root->right->sum;
        }
        return root;
    }
    void update(MyTreeNode* root, int i, int val) {
        if (root->begin == root->end) {
            root->sum = val;
        } else {
            int mid = root->begin + (root->end - root->begin) / 2;
            if (i <= mid) {
                update(root->left, i, val);
            } else {
                update(root->right, i, val);
            }
            root->sum = root->left->sum + root->right->sum;
        }
    }
    int sumRange(MyTreeNode* root, int i, int j) {
        if (!root) {
            return 0;
        }
        if (root->begin == i && root->end == j) {
            return root->sum;
        }
        int mid = root->begin + (root->end - root->begin) / 2;
        if (i > mid) {
            return sumRange(root->right, i, j);
        } else if (j <= mid) {
            return sumRange(root->left, i, j);
        } else {
            return sumRange(root->left, i, mid) + sumRange(root->right, mid + 1, j);
        }
    }
public:
    NumArray(vector<int> &nums) : _nums(nums) {
        if (nums.empty()) {
            return;
        }
        root = construct(0, nums.size() - 1, nums);
    }

    void update(int i, int val) {
        if (i < 0 || i >= _nums.size()) {
            return;
        }
        update(root, i, val);
    }

    int sumRange(int i, int j) {
        if (i > j) {
            return - 1;
        }
        return sumRange(root, i, j);
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

class NumArray {
private:
    vector<int> _nums;
    vector<int> _tree;
    void updateTree(int i, int val) {
        i = i + 1;
        while (i <= _nums.size()) {
            _tree[i] += val;
            i += i & (-i);
        }
    }
    int getSum(int i) {
        int sum = 0;
        i = i + 1;
        while (i > 0) {
            sum += _tree[i];
            i -= i & (-i);
        }
        return sum;
    }
public:
    NumArray(vector<int> &nums)
    : _nums(nums), _tree(vector<int>(nums.size() + 1)) {
        for (int i = 0; i < nums.size(); ++i) {
            updateTree(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - _nums[i];
        updateTree(i, diff);
        _nums[i] = val;
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return getSum(j);
        }
        return getSum(j) - getSum(i - 1);
    }
};

