class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.length() > 0) {
            vector<int> dp(s.length() + 1);
            dp[0] = 1;
            for (int i = 1; i < dp.size(); ++i) {
                for (int j = i - 1; j >= 0; --j) {
                    if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            return dp[s.length()];
        }
        return dict.find(s) != dict.end();
    }
};

// alternative
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<int> dp(s.length() + 1);
        dp[0] = 1;
        for (int i = 1; i < s.length() + 1; ++i) {
            for (int j = 1; j < i + 1; ++j) {
                if (dict.find(s.substr(j - 1, i - j + 1)) != dict.end() && dp[j - 1]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};

