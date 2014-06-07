class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string, int> dict;
        if (strs.size() > 0) {
            for (int i = 0; i < strs.size(); ++i) {
                string s = strs[i];
                sort(s.begin(), s.end());
                if (dict.find(s) != dict.end()) {
                    res.push_back(strs[i]);
                    if (dict[s] != -1) {
                        res.push_back(strs[dict[s]]);
                        dict[s] = -1;
                    }
                } else {
                    dict[s] = i;
                }
            }
        }
        return res;
    }
};

