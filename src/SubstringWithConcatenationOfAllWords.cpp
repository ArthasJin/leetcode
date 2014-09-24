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

// alternative
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, int> dict;
        for (int i = 0; i < L.size(); ++i) {
            dict[L[i]] += 1;
        }
        vector<int> res;
        int len = L[0].length();
        for (int i = 0; i < S.length() - L.size() * len + 1; ++i) {
            unordered_map<string, int> d;
            int j = 0;
            for (; j < L.size(); ++j) {
                string sub = S.substr(i + j * len, len);
                if (dict.find(sub) != dict.end()) {
                    d[sub] += 1;
                    if (d[sub] > dict[sub]) {
                        break;
                    }
                } else {
                    break;
                }
            }
            if (j == L.size()) {
                res.push_back(i);
            }
        }
        return res;
    }
};

// alternative
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, int> dict;
        for (int i = 0; i < L.size(); ++i) {
            dict[L[i]] += 1;
        }
        int size = L.size();
        int len = L[0].length();
        vector<int> res;
        for (int i = 0; i < S.length() - len * size + 1; ++i) {
            unordered_map<string, int> d = dict;
            for (int j = i; j < S.length(); j += len) {
                string sub = S.substr(j, len);
                if (dict.find(sub) != dict.end()) {
                    d[sub] -= 1;
                    if (d[sub] == 0) {
                        d.erase(sub);
                    }
                } else {
                    break;
                }
                if (d.size() == 0) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};

