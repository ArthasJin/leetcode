class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s) {
            string str(s);
            int last = str.find_last_not_of(" ");
            int start = last;
            while(start >= 0 && str[start] != ' ') {
                start--;
            }
            return last - start;
        }
        return 0;
    }
};

// alternative
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s) {
            int len = strlen(s);
            char *end = (char *) (s + len - 1);
            while (end >= s && *end == ' ') {
                end--;
            }
            if (end >= s) {
                char *start = end;
                while (start >= s && *start != ' ') {
                    start--;
                }
                return end - start;
            }
        }
        return 0;
    }
};

