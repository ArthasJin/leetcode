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

