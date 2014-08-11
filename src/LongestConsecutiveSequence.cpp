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

// more elegant solution
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> dict;
        for (int i = 0; i < num.size(); ++i) {
            dict[num[i]] = false;
        }
        int res = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (!dict[num[i]]) {
                int count = 1;
                int j = num[i];
                while(dict.find(++j) != dict.end()) {
                    dict[j] = true;
                    count++;
                }
                j = num[i];
                while(dict.find(--j) != dict.end()) {
                    dict[j] = true;
                    count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};

