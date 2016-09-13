class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int dict[256] = { 0 };
        int num = 0, res = 0, start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (dict[s[i]] == 0) {
                num++;
            }
            dict[s[i]]++;
            if (num > k) {
                while (--dict[s[start]] > 0) {
                    start++;
                }
                start++;
                num--;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};

