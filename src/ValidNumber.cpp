class Solution {
public:
    bool isNumber(const char *s) {
        char *end = NULL;
        strtod(s, &end);
        if (end == s) {
            return false;
        }
        while(*end) {
            if (*end != ' ') {
                return false;
            }
            end++;
        }
        return true;
    }
};

// alternative
class Solution {
public:
    bool isNumber(const char *s) {
        if (!s) {
            return false;
        }
        while(isspace(*s)) {
            s++;
        }
        if (*s == '+' || *s == '-') {
            s++;
        }
        bool hasExp = false, hasDot = false, firstPart = false, secondPart = false, hasSpace = false;
        while (*s != '\0') {
            if (*s == '.') {
                if (hasExp || hasDot || hasSpace) {
                    return false;
                } else {
                    hasDot = true;
                }
            } else if (*s == 'E' || *s == 'e') {
                if (hasExp || !firstPart || hasSpace) {
                    return false;
                } else {
                    hasExp = true;
                }
            } else if (isdigit(*s)) {
                if (hasSpace) {
                    return false;
                }
                if (!hasExp) {
                    firstPart = true;
                } else {
                    secondPart = true;
                }
            } else if (*s == '+' || *s == '-') {
                if (hasSpace) {
                    return false;
                }
                if (!hasExp || !(*(s - 1) == 'e' || *(s - 1) == 'E')) {
                    return false;
                }
            } else if (isspace(*s)) {
                hasSpace = true;
            } else {
                return false;
            }
            s++;
        }
        if (!firstPart) {
            return false;
        } else if (hasExp && !secondPart) {
            return false;
        }
        return true;
    }
};

