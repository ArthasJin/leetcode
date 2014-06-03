// dfs TLE
class Solution {
public:
    int numDecodings(string s) {
        for (int i = 0; i < 26; ++i) {
            alpha.push_back('A' + i);
        }
        decode(s, 0);
        return res;
    }
private:
    vector<char> alpha;
    int res;
    bool isValid(string &s) {
        if (s.length() == 1) {
            return s[0] >= '1' && s[0] <= '9';
        } else if (s.length() == 2) {
            int num = atoi(s.c_str());
            return s[0] != '0' && num > 10 && num <= 26;
        }
        return false;
    }
    void decode(string &s, int start) {
        if (start >= s.length()) {
            res++;
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            string sub = s.substr(i, 1);
            if (isValid(sub)) {
                decode(s, i + 1);
            }
            if (i + 1 < s.length()) {
                sub = s.substr(i, 2);
                if (isValid(sub)) {
                    decode(s, i + 2);
                }
            }
        }
    }
};

// dp
class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        vector<int> dp(s.length());
        string sub = s.substr(0, 1);
        if (isValid(sub)) {
            dp[0] = 1;
        }
        if (s.length() == 1) {
            return dp[0];
        }
        sub = s.substr(0, 2);
        if (isValid(sub)) {
            dp[1] = 1;
        }
        sub = s.substr(1, 1);
        if (s[0] != '0' && isValid(sub)) {
            dp[1]++;
        }
        for (int i = 2; i < s.length(); ++i) {
            sub = s.substr(i, 1);
            if (isValid(sub)) dp[i] += dp[i - 1];
            sub = s.substr(i - 1, 2);
            if (isValid(sub)) dp[i] += dp[i - 2];
        }
        return dp[s.length() - 1];
    }
private:
    bool isValid(string &s) {
        if (s.length() == 1) {
            return s[0] >= '1' && s[0] <= '9';
        } else if (s.length() == 2) {
            int num = atoi(s.c_str());
            return s[0] != '0' && num >= 10 && num <= 26;
        }
        return false;
    }
};

