class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<bool> > p(s.length(), vector<bool>(s.length()));
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                string str = s.substr(i, j - i + 1);
                if (dict.find(str) != dict.end()) {
                    p[i][j] = true;
                }
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            if (p[i][s.length() - 1]) {
                string path;
                wordBreak(s, 0, path, dict, p);
                break;
            }
        }
        return res;
    }
private:
    vector<string> res;
    void wordBreak(string &s, int start, string &path, unordered_set<string> &dict, vector<vector<bool> > &p) {
        if (start == s.length()) {
            res.push_back(path.substr(0, path.length() - 1));
            return;
        }
        string prev = path;
        for (int i = 0; i < s.length(); ++i) {
            if (p[start][i]) {
                path += s.substr(start, i - start + 1) + " ";
                wordBreak(s, i + 1, path, dict, p);
                path = prev;
            }
        }
    }
};

