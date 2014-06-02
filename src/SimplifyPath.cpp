class Solution {
public:
    string simplifyPath(string path) {
        if (path.length() > 0) {
            char *token = strtok(&path[0], "/");
            stack<string> stk;
            while(token) {
                string s(token);
                if (s == ".." && !stk.empty()) {
                    stk.pop();
                } else if (s == ".") {
                    // do nothing
                } else if (s != ".." && s.length() > 0) {
                    stk.push(s);
                }
                token = strtok(NULL, "/");
            }
            string res;
            while(!stk.empty()) {
                res = "/" + stk.top() + res;
                stk.pop();
            }
            if (res.empty()) {
                return "/";
            }
            return res;
        }
        return string();
    }
};

