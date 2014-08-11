class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        if (n > 0) {
            int i = 1, x = 0, y = 0;
            matrix[0][0] = i++;
            while(i <= n * n) {
                while(y + 1 < n && matrix[x][y + 1] == 0) {
                    matrix[x][++y] = i++;
                }
                while(x + 1 < n && matrix[x + 1][y] == 0) {
                    matrix[++x][y] = i++;
                }
                while(y - 1 >= 0 && matrix[x][y - 1] == 0) {
                    matrix[x][--y] = i++;
                }
                while(x - 1 >= 0 && matrix[x - 1][y] == 0) {
                    matrix[--x][y] = i++;
                }
            }
        }
        return matrix;
    }
};

// more tuitive solution
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));
        int start = 0, col = n, row = n, count = 1;
        while(col > start * 2 && row > start * 2) {
            int endCol = col - 1 - start;
            int endRow = row - 1 - start;
            for (int i = start; i < endCol + 1; ++i) {
                res[start][i] = count;
                count++;
            }
            for (int i = start + 1; i < endRow + 1; ++i) {
                res[i][endCol] = count;
                count++;
            }
            for (int i = endCol - 1; i >= start; --i) {
                res[endRow][i] = count;
                count++;
            }
            for (int i = endRow - 1; i > start; --i) {
                res[i][start] = count;
                count++;
            }
            start++;
        }
        return res;
    }
};

