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

