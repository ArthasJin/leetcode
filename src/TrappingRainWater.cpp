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

