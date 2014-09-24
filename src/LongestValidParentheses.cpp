class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() > 0) {
            stack<pair<int, int> > stk;
            int len = 0, t = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] == '(') {
                    stk.push(make_pair(s[i], i));
                } else {
                    if (stk.empty()) {
                        t = i + 1;
                    } else {
                        pair<int, int> p = stk.top();
                        stk.pop();
                        if (p.first == '(') {
                            if (!stk.empty()) {
                                len = max(len, i - stk.top().second);
                            } else {
                                len = max(len, i - t + 1);
                            }
                        }
                    }
                }
            }
            return len;
        }
        return 0;
    }
};

// alternative
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (!stk.empty()) {
                    int p = stk.top();
                    if (s[p] == '(') {
                        stk.pop();
                    } else {
                        stk.push(i);
                    }
                    if (stk.empty()) {
                        res = max(res, i + 1);
                    } else {
                        res = max(res, i - stk.top());
                    }
                } else {
                    stk.push(i);
                }
            }
        }
        return res;
    }
};

