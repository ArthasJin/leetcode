class Solution {
public:
    int minCut(string s) {
        if (s.length() > 0) {
            vector<vector<bool> > dict(s.length(), vector<bool>(s.length()));
            vector<int> res(s.length());
            for (int i = s.length() - 1; i >= 0; --i) {
                for (int j = i; j < s.length(); ++j) {
                    if (s[i] == s[j] && ((j - i < 2) || dict[i + 1][j - 1])) {
                        dict[i][j] = true;
                    }
                }
            }
            for (int i = 0; i < s.length(); ++i) {
                int cut = s.length();
                if (dict[0][i]) {
                    res[i] = 0;
                } else {
                    for (int j = 0; j < i; ++j) {
                        if (dict[j + 1][i] && cut > res[j] + 1) {
                            cut = res[j] + 1;
                        }
                    }
                    res[i] = cut;
                }
            }
            return res[s.length() - 1];
        }
        return 0;
    }
};

