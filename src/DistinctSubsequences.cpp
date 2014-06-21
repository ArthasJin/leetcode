class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.length();
        int n = T.length();
        if (m < n) return 0;
        vector<vector<int> > dp(m, vector<int>(n));
        if (S[0] == T[0]) dp[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            if (S[i] == T[0]) {
                dp[i][0] = dp[i - 1][0] + 1;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (S[i] == T[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

