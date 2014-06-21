class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 1, start = 0;
        bool dp[1000][1000] = { false };
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

