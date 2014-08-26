class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') {
            return *s == '\0';
        }
        if (*(p + 1) != '*') {
            if (*p == *s || (*p == '.' && *s != '\0'))
                return isMatch(s + 1, p + 1);
            else {
                return false;
            }
        } else {
            while (*p == *s || (*p == '.' && *s != '\0')) {
                if (isMatch(s, p + 2)) {
                    return true;
                }
                s++;
            }
            return isMatch(s, p + 2);
        }
    }
};

// alternative
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s || !p) {
            return false;
        }
        if (*p == '\0') {
            return *s == '\0';
        }
        if (*(p + 1) != '*') {
            return ((*s == *p) || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
        }
        while ((*p == *s) || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p + 2)) {
                return true;
            }
            s++;
        }
        return isMatch(s, p + 2);
    }
};

