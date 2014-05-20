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

