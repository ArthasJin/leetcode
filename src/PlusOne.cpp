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

// a little elegent
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1, i = digits.size() - 1;
        vector<int> res;
        while(i >= 0) {
            int sum = digits[i] + carry;
            carry = sum / 10;
            res.push_back(sum % 10);
            i--;
        }
        if (carry) {
            res.push_back(1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// space O(1)
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1, i = 0;
        while (carry && i < digits.size()) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            i++;
        }
        if (carry) {
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

