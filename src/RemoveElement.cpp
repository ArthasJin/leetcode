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

