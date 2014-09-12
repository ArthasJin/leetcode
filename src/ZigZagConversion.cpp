class Solution {
public:
    string convert(string s, int nRows) {
        if (s.length() == 0 || nRows < 2) {
            return s;
        }
        string res;
        int size = nRows * 2 - 2;
        for (int i = 0; i < nRows; ++i) {
            for (int j = i; j < s.length(); j += size) {
                res.push_back(s[j]);
                if (i != 0 && i != nRows - 1 && j + size - 2 * i < s.length()) {
                    res.push_back(s[j + size - 2 * i]);
                }
            }
        }
        return res;
    }
};

