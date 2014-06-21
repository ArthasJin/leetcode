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

