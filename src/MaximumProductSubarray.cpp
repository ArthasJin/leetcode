class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n < 1) {
            return 0;
        }
        int maxProd, minProd, res;
        maxProd = minProd = res = A[0];
        for (int i = 1; i < n; ++i) {
            int maxCur = maxProd * A[i];
            int minCur = minProd * A[i];
            int cur = A[i];
            maxProd = max(max(maxCur, minCur), cur);
            minProd = min(min(maxCur, minCur), cur);
            res = max(res, maxProd);
        }
        return res;
    }
};

