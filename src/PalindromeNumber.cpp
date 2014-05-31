class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int bit = log10(x);
        int p = pow(10, bit);
        int res = true;
        for (int i = 0; i < (bit + 1) / 2; ++i) {
            if (x % 10 != x / p) {
                res = false;
                break;
            } else {
                x -= x / p * p;
                x /= 10;
                p /= 100;
            }
        }
        return res;
    }
};

