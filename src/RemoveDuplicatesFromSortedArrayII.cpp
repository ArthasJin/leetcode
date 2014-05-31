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
                } else if (A[cur] == A[i] && count == 1) {
                    continue;
                }
            }
            return cur + 1;
        }
        return n;
    }
};

