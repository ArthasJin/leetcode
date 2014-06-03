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

