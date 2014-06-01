class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() > 0) {
            unordered_map<int, bool> m;
            for (int i = 0; i < num.size(); ++i) {
                m[num[i]] = false;
            }
            int res = 0;
            for (int i = 0; i < num.size(); ++i) {
                if (m[num[i]]) {
                    continue;
                }
                m[num[i]] = true;
                int len = 1;
                for (int j = num[i] + 1; m.find(j) != m.end(); ++j) {
                    ++len;
                    m[num[j]] = true;
                }
                for (int j = num[i] - 1; m.find(j) != m.end(); --j) {
                    ++len;
                    m[num[j]] = true;
                }
                res = max(res, len);
            }
            return res;
        }
        return 0;
    }
};

