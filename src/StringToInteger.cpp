class Solution {
public:
    int atoi(const char *str) {
        if (str) {
            int i = 0, sign = 1, res = 0;
            while(str[i] == ' ') {
                i++;
            }
            if (str[i] == '+') {
                sign = 1;
                i++;
            } else if (str[i] == '-') {
                sign = -1;
                i++;
            }
            if (!isdigit(str[i])) {
                return 0;
            }
            while(isdigit(str[i])) {
                if (sign > 0 && res > INT_MAX / 10) {
                    return INT_MAX;
                }
                if (sign > 0 && res == INT_MAX / 10 && str[i] - '0' >= 7) {
                    return INT_MAX;
                }
                if (sign < 0 && -res < INT_MIN / 10) {
                    return INT_MIN;
                }
                if (sign < 0 && -res == INT_MIN / 10 && str[i] - '0' >= 8) {
                    return INT_MIN;
                }
                res = res * 10 + str[i] - '0';
                i++;
            }
            return res * sign;
        }
        return 0;
    }
};

