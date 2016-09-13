class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int dict[255] = { 0 };
        int res = 0, distinct = 0, start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (dict[s[i]] == 0) {
                distinct++;
            }
            dict[s[i]]++;
            if (distinct > 2) {
                while (--dict[s[start]] > 0) {
                    start++;
                }
                start++;
                distinct--;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};

