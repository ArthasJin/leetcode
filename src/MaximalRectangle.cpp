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

// alternative
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        vector<vector<int> > m(row, vector<int>(col));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '0') {
                    m[i][j] = 0;
                } else {
                    if (i - 1 >= 0) {
                        m[i][j] = m[i - 1][j] + 1;
                    } else {
                        m[i][j] = 1;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < row; ++i) {
            res = max(largestRectangleArea(m[i]), res);
        }
        return res;
    }
private:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() > 0) {
            height.push_back(0);
            stack<int> stk;
            int i = 0, res = 0;
            while (i < height.size()) {
                if (stk.empty() || height[i] > height[stk.top()]) {
                    stk.push(i);
                    i++;
                } else {
                    int index = stk.top();
                    stk.pop();
                    int width = stk.empty() ? i : i - stk.top() - 1;
                    res = max(res, height[index] * width);
                }
            }
            return res;
        }
        return 0;
    }
};

