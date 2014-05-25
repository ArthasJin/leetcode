class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        digits[digits.size() - 1] += 1;
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += carry;
            carry = digits[i] == 10? 1 : 0;
            res.push_back(digits[i] % 10);
        }
        if (carry) {
            res.push_back(1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

