class Solution {
public:
    bool isValid(string s) {
        if (s.length() > 0) {
            stack<char> stk;
            for (int i = 0; i < s.length(); ++i) {
                char ch = s[i];
                switch(ch) {
                case '(':
                case '{':
                case '[':
                    stk.push(ch);
                    break;
                case ')':
                    if (stk.size() == 0) return false;
                    if (stk.top() == '(') stk.pop();
                    else stk.push(ch);
                    break;
                case '}':
                    if (stk.size() == 0) return false;
                    if (stk.top() == '{') stk.pop();
                    else stk.push(ch);
                    break;
                case ']':
                    if (stk.size() == 0) return false;
                    if (stk.top() == '[') stk.pop();
                    else stk.push(ch);
                    break;
                }
            }
            return stk.size() == 0;
        }
        return true;;
    }
};

// alternative
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> dict;
        dict[')'] = '(', dict[']'] = '[', dict['}'] = '{';
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            } else {
                if (!stk.empty()) {
                    char p = stk.top();
                    if (dict[ch] == p) {
                        stk.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

