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

