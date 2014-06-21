class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int len = m + n;
        if (len & 0x01) {
            return findMedian(A, m, B, n, len / 2 + 1);
        } else {
            return (findMedian(A, m, B, n, len / 2) + findMedian(A, m, B, n, len / 2 + 1)) / 2;
        }
    }
private:
    double findMedian(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return findMedian(B, n, A, m, k);
        }
        if (m == 0) {
            return B[k - 1];
        }
        if (k == 1) {
            return min(A[0], B[0]);
        }
        int pa = min(k / 2, m);
        int pb = k - pa;
        if (A[pa - 1] < B[pb - 1]) {
            return findMedian(A + pa, m - pa, B, n, k - pa);
        }
        return findMedian(A, m, B + pb, n - pb, k - pb);
    }
};

