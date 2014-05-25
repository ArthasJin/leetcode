class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string input;
        generate(n, 0, input);
        return res;
    }
private:
    vector<string> res;
    bool isValid(string &input) {
        int flag = 0;
        for (int i = 0; i < input.length(); ++i) {
            if (flag < 0) {
                return false;
            } else if (input[i] == '(') {
                flag++;
            } else if (input[i] == ')') {
                flag--;
            }
        }
        return flag == 0;
    }
    void generate(int n, int index, string &input) {
        if (n * 2 == index) {
            if (isValid(input)) {
                res.push_back(input);
            }
            return;
        }
        input.push_back('(');
        generate(n, index + 1, input);
        input.pop_back();
        input.push_back(')');
        generate(n, index + 1, input);
        input.pop_back();
    }
};

