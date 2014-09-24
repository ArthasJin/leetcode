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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dict;
        int res = 0, start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (dict.find(s[i]) != dict.end()) {
                removeDup(dict, start, dict[s[i]], s);
                start = dict[s[i]] + 1;
            }
            dict[s[i]] = i;
            res = max(res, i - start + 1);
        }
        return res;
    }
private:
    void removeDup(unordered_map<char, int> &dict, int start, int end, string &s) {
        for (int i = start; i < end; ++i) {
            dict.erase(s[i]);
        }
    }
};

// alternative
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, res = 0;
        int dict[255] = { 0 };
        while (start < s.length() && end < s.length()) {
            if (dict[s[end]] == 0) {
                dict[s[end]] = 1;
                res = max(res, end - start + 1);
                end++;
            } else {
                dict[s[start]] = 0;
                res = max(res, end - start);
                start++;
            }
        }
        return res;
    }
};

