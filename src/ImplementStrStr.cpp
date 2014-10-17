class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        string s(haystack);
        if (s.find(needle) != string::npos) {
            return haystack + s.find(needle);
        }
        return NULL;
    }
};

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack && needle) {
            int len1 = strlen(haystack);
            int len2 = strlen(needle);
            for (int i = 0; i < len1 - len2 + 1; ++i) {
                char *s1 = haystack + i, *s2 = needle;
                while (*s1 == *s2 && *s2 != '\0') {
                    s1++, s2++;
                }
                if (*s2 == '\0') {
                    return haystack + i;
                }
            }
        }
        return NULL;
    }
};

