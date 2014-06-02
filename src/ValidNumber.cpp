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

