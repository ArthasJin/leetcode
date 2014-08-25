class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0) {
            return "";
        }
        bool pos = true;
        if (num1[0] == '-') {
            num1 = num1.substr(1);
            pos = !pos;
        }
        if (num2[0] == '-') {
            num2 = num2.substr(1);
            pos = !pos;
        }
        //main part
        string res = "0";
        for (int i = num2.size() - 1; i >= 0; i--) {
            string m = mpl(num1, num2[i]); // num1 multiply by num2[i]
            if (m != "0") {
                add(res, m, num2.size() - 1 - i); // add m to the result
            }
        }
        if (!pos) {
            res = "-" + res;
        }
        return res;
    }
private:
    string mpl(string num, char n) {
        string res;
        int carry = 0;
        if (n == '0') {
            return "0";
        }
        for (int i = num.size() - 1; i >= 0; i--) {
            int m = (num[i] - '0') * (n - '0') + carry;
            carry = m / 10;
            m = m % 10;
            res = char(m + '0') + res;
        }
        if (carry != 0) {
            res = char(carry + '0') + res;
        }
        return res;
    }
    void add(string &res, string m,int idx) {
        if (res == "") {
            res = m;
        } else {
            m = m + string(idx, '0');
            int carry = 0;
            int i = res.size() - 1;
            int j = m.size() - 1;
            while (i >= 0) {
                int k = (res[i] - '0') + (m[j] - '0') + carry;
                carry = k / 10;
                k= k % 10;
                res[i] = char(k + '0');
                i--;
                j--;
            }
            while (j >= 0) {
                if (carry > 0) {
                    int kk = (m[j] - '0') + carry;
                    carry = kk / 10;
                    kk = kk % 10;
                    res = char(kk + '0') + res;
                } else {
                    res = m[j] + res;
                }
                j--;
            }
            if (carry>0) {
                res = char(carry+'0') + res;
            }
        }
    }
};

// alternative
class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "0";
        for (int i = num2.size() - 1; i >= 0; --i) {
            string p = multiply(num1, num2[i]);
            if (p != "0") {
                for (int j = 0; j < num2.size() - i - 1; ++j) {
                    p += "0";
                }
                res = add(p, res);
            }
        }
        return res;
    }
private:
    string multiply(string &num, char c) {
        if (c == '0') {
            return "0";
        }
        string res;
        int carry = 0;
        for (int i = num.size() - 1; i >= 0; --i) {
            int m = (num[i] - '0') * (c - '0') + carry;
            res = char(m % 10 + '0') + res;
            carry = m / 10;
        }
        if (carry) {
            res = char(carry + '0') + res;
        }
        return res;
    }
    string add(string &a, string &b) {
        int carry = 0, i_a = a.length() - 1, i_b = b.length() - 1;
        string res;
        while(i_a >= 0 || i_b >= 0) {
            int val1 = i_a >= 0 ? a[i_a] - '0' : 0;
            int val2 = i_b >= 0 ? b[i_b] - '0' : 0;
            int sum = val1 + val2 + carry;
            char ch = sum % 10 + '0';
            carry = sum / 10;
            res.push_back(ch);
            i_a--, i_b--;
        }
        if (carry) {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

