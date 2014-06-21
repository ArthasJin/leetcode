class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() > 0) {
            int len = 0, maxLen = 0;
            unordered_map<char, int> dict;
            for (int i = 0; i < s.length(); ++i, ++len) {
                if (dict.find(s[i]) != dict.end()) {
                    maxLen = max(len, maxLen);
                    len = 0;
                    i = dict[s[i]] + 1;
                    dict.clear();
                } else {
                    dict[s[i]] = i;
                }
            }
            return max(maxLen, len);
        }
        return 0;
    }
};

