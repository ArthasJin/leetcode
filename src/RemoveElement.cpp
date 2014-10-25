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

// more elegant solution
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int end = n - 1, i = 0;
        while (i < end + 1) {
            if (A[i] == elem) {
                swap(A[i], A[end]);
                end--;
            } else {
                i++;
            }
        }
        return i;
    }
};

