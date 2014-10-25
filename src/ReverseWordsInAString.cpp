class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() > 0) {
            stack<const char *> stk;
            const char *token = strtok(&s[0], " ");
            while(token != NULL) {
                stk.push(token);
                token = strtok(NULL, " ");
            }
            string res;
            while(!stk.empty()) {
                res += string(stk.top()) + " ";
                stk.pop();
            }
            s = res.substr(0, res.length() - 1);
        }
    }
};

// should fix issue with mutliple inner spaces
class Solution {
public:
    void reverseWords(string &s) {
        while (s[0] == ' ') {
            s.erase(0, 1);
        }
        while (s[s.length() - 1] == ' ') {
            s.erase(s.length() - 1, 1);
        }
        int start = 0, end = 0;
        while (end < s.length() + 1) {
            if (s[end] == '\0') {
                reverse(s.begin() + start, s.begin() + end);
            } else if (s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
            end++;
        }
        reverse(s.begin(), s.end());
    }
};

