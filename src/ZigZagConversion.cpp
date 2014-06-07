class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows > 1) {
            vector<string> m(nRows);
            int i = 0, row = 0;
            bool isZigzag = false;
            while(i < s.length()) {
                if (row < nRows && !isZigzag) {
                    m[row] += s[i];
                    row++;
                    i++;
                } else {
                    if (!isZigzag) {
                        isZigzag = true;
                        row--;
                    } else {
                        row--;
                        m[row] += s[i];
                        i++;
                        if (row == 0) {
                            isZigzag = false;
                            row++;
                        }
                    }
                }
            }
            string res;
            for (int i = 0; i < m.size(); ++i) {
                for (int j = 0; j < m[i].length(); ++j) {
                    res += m[i][j];
                }
            }
            return res;
        }
        return s;
    }
};

