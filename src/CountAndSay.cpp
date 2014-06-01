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

