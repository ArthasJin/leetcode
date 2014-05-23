class Solution {
public:
    int singleNumber(int A[], int n) {
        int count[sizeof(int) * 8] = { 0 };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < sizeof(int) * 8; ++j) {
                count[j] += A[i] >> j & 0x01;
                count[j] %= 3;
            }
        }
        int res = 0;
        for (int i = 0; i < sizeof(int) * 8; ++i) {
            res += count[i] << i;
        }
        return res;
    }
};

