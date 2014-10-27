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

// alternative
class Solution {
public:
    int atoi(const char *str) {
        if (str) {
            while (*str != '\0' && *str == ' ') {
                str++;
            }
            int sign = 1;
            if (*str == '-') {
                sign = -1;
            }
            if (*str == '+' || *str == '-') {
                str++;
            }
            int res = 0;
            while (*str != '\0' && isdigit(*str)) {
                int n = *str - '0';
                if (sign == 1) {
                    if (res > INT_MAX / 10) {
                        return INT_MAX;
                    } else if (res == INT_MAX / 10 && n > INT_MAX % 10) {
                        return INT_MAX;
                    }
                    res = res * 10 + n;
                } else if (sign == -1) {
                    if (-res < INT_MIN / 10) {
                        return INT_MIN;
                    } else if (-res == INT_MIN / 10 && -n < INT_MIN % 10) {
                        return INT_MIN;
                    }
                    res = res * 10 + n;
                }
                str++;
            }
            return res * sign;
        }
        return 0;
    }
};

