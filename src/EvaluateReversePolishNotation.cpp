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

// more elegant solution
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        string ops = "+-*/";
        stack<int> stk;
        for (int i = 0; i < tokens.size(); ++i) {
            int op = ops.find(tokens[i]);
            if (op != string::npos) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(eval(a, b, ops[op]));
            } else {
                stk.push(atoi(&tokens[i][0]));
            }
        }
        return stk.top();
    }
private:
    int eval(int &n1, int &n2, char op) {
        switch(op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        }
    }
};

