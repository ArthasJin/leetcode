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

