class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        int res = 0;
        vector<vector<int> > p(row, vector<int>(col));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    if (j == 0) {
                        p[i][j] = 1;
                    } else {
                        p[i][j] = p[i][j - 1] + 1;
                    }
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (p[i][j] != 0) {
                    int h = i - 1;
                    int tmp = p[i][j];
                    int mini = p[i][j];
                    while(h >= 0) {
                        if (p[h][j] == 0) {
                            break;
                        } else {
                            mini = min(mini, p[h][j]);
                            tmp = max(tmp, mini * (i - h + 1));
                        }
                        h--;
                    }
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};

