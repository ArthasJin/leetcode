class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        int num = L.size();
        int len = L[0].size();
        if (num == 0) {
            return res;
        }
        unordered_map<string, int> dict;
        for (int i = 0; i < num; ++i) {
            dict[L[i]] += 1;
        }
        int i = 0;
        while ((i + num * len - 1) < S.size()) {
            unordered_map<string, int> selected;
            int j = 0;
            while (j < num) {
                string subs = S.substr(i + j * len, len);
                if (dict.find(subs) == dict.end()){
                    break;
                } else {
                    selected[subs]++;
                    if (selected[subs] > dict[subs]) {
                        break;
                    }
                    j++;
                }
            }
            if (j == num) {
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};

