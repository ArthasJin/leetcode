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

