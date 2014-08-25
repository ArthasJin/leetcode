class Solution {
public:
    string countAndSay(int n) {
        int current = n;
        if (current < 1) {
            return string();
        }
        string res = "1", tmp = "";
        for (int i = 1; i < n; ++i) {
            int length = res.length();
            int count = 1;
            for (int j = 0; j < length - 1; ++j) {
                if (res[j] == res[j + 1]) {
                    count++;
                    continue;
                } else {
                    tmp += char('0' + count);
                    tmp += res[j];
                    count = 1;
                }
            }
            tmp += char('0' + count);
            tmp += res[length - 1];
            res = tmp;
            tmp = "";
        }
        return res;
    }
};

// more elegant solution
class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) {
            return string();
        }
        string res = "1", tmp = "";
        for (int i = 1; i < n; ++i) {
            int len = res.length();
            int count = 1;
            for (int j = 0; j < len - 1; ++j) {
                if (res[j] == res[j + 1]) {
                    count++;
                } else {
                    tmp += '0' + count;
                    tmp += res[j];
                    count = 1;
                }
            }
            tmp += '0' + count;
            tmp += res[len - 1];
            res = tmp;
            tmp = "";
        }
        return res;
    }
};

// more elegant solution
class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        for (int i = 1; i < n; ++i) {
            char cur = prev[0];
            int count = 1;
            string tmp;
            for (int j = 1; j < prev.length() + 1; ++j) {
                if (prev[j] == cur) {
                    count++;
                } else {
                    tmp += count + '0';
                    tmp.push_back(cur);
                    cur = prev[j];
                    count = 1;
                }
            }
            prev = tmp;
        }
        return prev;
    }
};

