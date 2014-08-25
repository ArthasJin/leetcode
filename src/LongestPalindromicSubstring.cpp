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

// alternative
class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1000][1000] = { false };
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
        }
        int start = 0, end = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                end = i + 1;
            }
        }
        for (int i = s.length() - 3; i >= 0; --i) {
            for (int j = i + 2; j < s.length(); ++j) {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if ((j - i) > (end - start)) {
                        start = i;
                        end = j;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// more elegant solution
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        bool dp[1000][1000] = { false };
        for (int i = s.length() - 1; i >= 0; --i) {
            for (int j = i; j < s.length(); ++j) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                    if (j - i > end - start) {
                        start = i;
                        end = j;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};

