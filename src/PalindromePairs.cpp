class Solution {
private:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]] = i;
        }
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].length(); ++j) {
                if (isPalindrome(words[i], j, words[i].length() - 1)) {
                    string suffix = words[i].substr(0, j);
                    reverse(suffix.begin(), suffix.end());
                    if (m.count(suffix) && m[suffix] != i) {
                        res.push_back({ i, m[suffix] });
                    }
                }
                if (j > 0 && isPalindrome(words[i], 0, j - 1)) {
                    string prefix = words[i].substr(j);
                    reverse(prefix.begin(), prefix.end());
                    if (m.count(prefix) && m[prefix] != i) {
                        res.push_back({ m[prefix], i });
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

