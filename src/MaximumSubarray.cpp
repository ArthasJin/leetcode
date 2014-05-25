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

