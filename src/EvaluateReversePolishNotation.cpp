class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() > 0) {
            stack<int> stk;
            for (int i = 0; i < tokens.size(); ++i) {
                if (tokens[i] == "+") {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op1 + op2);
                } else if (tokens[i] == "-") {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op2 - op1);
                } else if (tokens[i] == "*") {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op2 * op1);
                } else if (tokens[i] == "/") {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op2 / op1);
                } else {
                    stk.push(atoi(tokens[i].c_str()));
                }
            }
            return stk.top();
        }
        return 0;
    }
};

