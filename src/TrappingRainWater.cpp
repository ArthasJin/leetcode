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

