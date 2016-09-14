class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n > 0) {
            int bit = 0;
            while (n > 0) {
                if (n & 0x01) {
                    bit += 1;
                }
                if (bit > 1) {
                    return false;
                }
                n >>= 1;
            }
            return true;
        }
        return false;
    }
};

