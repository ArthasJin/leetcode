class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = 0, carry = 0;
        while(i < a.length() || i < b.length()) {
            int val1 = i < a.length()? a[a.length() - 1 - i] - '0' : 0;
            int val2 = i < b.length()? b[b.length() - 1 - i] - '0' : 0;
            int sum = val1 + val2 + carry;
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
            i++;
        }
        if (carry) {
            res.push_back(1 + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

