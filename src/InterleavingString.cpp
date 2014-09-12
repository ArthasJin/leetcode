class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() > 0 && s1.length() + s2.length() == s3.length()) {
            vector<vector<bool> > dp(s1.length() + 1, vector<bool>(s2.length() + 1));
            dp[0][0] = true;
            for (int i = 1; i < dp.size(); ++i) {
                if (s1[i - 1] == s3[i - 1] && dp[i - 1][0]) {
                    dp[i][0] = true;
                }
            }
            for (int j = 1; j < dp[0].size(); ++j) {
                if (s2[j - 1] == s3[j - 1] && dp[0][j - 1]) {
                    dp[0][j] = true;
                }
            }
            for (int i = 1; i < dp.size(); ++i) {
                for (int j = 1; j < dp[0].size(); ++j) {
                    if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] || s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
            return dp[s1.length()][s2.length()];
        }
        return s1.length() == 0 && s2.length() == 0 && s3.length() == 0;
    }
};

// alternative
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() == s3.length()) {
            vector<vector<int> > dp(s1.length() + 1, vector<int>(s2.length() + 1));
            dp[0][0] = 1;
            for (int i = 1; i < s1.length() + 1; ++i) {
                dp[i][0] = s1[i - 1] == s3[i - 1];
            }
            for (int i = 1; i < s2.length() + 1; ++i) {
                dp[0][i] = s2[i - 1] == s3[i - 1];
            }
            for (int i = 1; i < s1.length() + 1; ++i) {
                for (int j = 1; j < s2.length() + 1; ++j) {
                    dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
                }
            }
            return dp[s1.length()][s2.length()];
        }
        return false;
    }
};

