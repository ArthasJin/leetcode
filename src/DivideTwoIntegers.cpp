class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((double) dividend);
        long long b = abs((double) divisor);
        long long res = 0;
        while(a >= b) {
            long long c = b;
            for (int i = 0; a >= c; ++i, c <<= 1) {
                a -= c;
                res += 1 << i;
            }
        }
        return (dividend ^ divisor) >> 31 ? -res : res;
    }
};

