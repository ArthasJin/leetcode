class Solution {
public:
    int reverse(int x) {
        int sign = x > 0? 1: -1;
        int num = x * sign;
        int res = 0;
        while(num > 0) {
            int remain = num % 10;
            res = res * 10 + remain;
            num /= 10;
        }
        if (res < 0) {
            return -1;
        }
        return res * sign;
    }
};

