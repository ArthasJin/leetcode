class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() > 0 && word2.length() > 0) {
            vector<vector<int> > dp(word1.length() + 1, vector<int>(word2.length() + 1));
            for (int i = 0; i < word1.length() + 1; ++i) {
                dp[i][0] = i;
            }
            for (int j = 0; j < word2.length() + 1; ++j) {
                dp[0][j] = j;
            }
            for (int i = 1; i < word1.length() + 1; ++i) {
                for (int j = 1; j < word2.length() + 1; ++j) {
                    int diff = word1[i - 1] == word2[j - 1]? 0 : 1;
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + diff);
                }
            }
            return dp[word1.length()][word2.length()];
        }
        return word1.length() == 0? word2.length() : word1.length();
    }
};

