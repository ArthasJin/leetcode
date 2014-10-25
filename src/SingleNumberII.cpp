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

// a little optmized
class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n > 0) {
            int bit[32] = { 0 };
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 32; ++j) {
                    if (A[i] >> j == 0) {
                        break;
                    }
                    bit[j] += A[i] >> j & 0x01;
                    bit[j] %= 3;
                }
            }
            int res = 0;
            for (int i = 0; i < 32; ++i) {
                res |= bit[i] << i;
            }
            return res;
        }
        return 0;
    }
};

