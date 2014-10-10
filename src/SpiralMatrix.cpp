class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int row = matrix.size();
        int col;
        if (row > 0) {
            col = matrix[0].size();
            vector<vector<int> > visited(row, vector<int>(col, 0));
            res.push_back(matrix[0][0]);
            visited[0][0] = 1;
            int i = 0, x = 0, y = 0;
            while(i < row * col - 1) {
                while(y + 1 < col && visited[x][y + 1] == 0) {
                    y++;
                    i++;
                    res.push_back(matrix[x][y]);
                    visited[x][y] = 1;
                }
                while(x + 1 < row && visited[x + 1][y] == 0) {
                    x++;
                    i++;
                    res.push_back(matrix[x][y]);
                    visited[x][y] = 1;
                }
                while(y - 1 >= 0 && visited[x][y - 1] == 0) {
                    y--;
                    i++;
                    res.push_back(matrix[x][y]);
                    visited[x][y] = 1;
                }
                while(x - 1 >= 0 && visited[x - 1][y] == 0) {
                    x--;
                    i++;
                    res.push_back(matrix[x][y]);
                    visited[x][y] = 1;
                }
            }
        }
        return res;
    }
};

// more elegant solution
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int row = matrix.size();
        if (row == 0) {
            return res;
        }
        int col = matrix[0].size();
        int start = 0;
        vector<vector<int> > visited(row, vector<int>(col, 0));
        while(row > start * 2 && col > start * 2) {
            int endRow = row - 1 - start;
            int endCol = col - 1 - start;
            for (int i = start; i < endCol + 1 && !visited[start][i]; ++i) {
                res.push_back(matrix[start][i]);
                visited[start][i] = 1;
            }
            for (int i = start + 1; i < endRow + 1 && !visited[i][endCol]; ++i) {
                res.push_back(matrix[i][endCol]);
                visited[i][endCol] = 1;
            }
            for (int i = endCol - 1; i >= start && !visited[endRow][i]; --i) {
                res.push_back(matrix[endRow][i]);
                visited[endRow][i] = 1;
            }
            for (int i = endRow - 1; i > start && !visited[i][start]; --i) {
                res.push_back(matrix[i][start]);
                visited[i][start] = 1;
            }
            start++;
        }
        return res;
    }
};

// alternative space O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int row = matrix.size();
        if (row == 0) {
            return res;
        }
        int col = matrix[0].size();
        int start = 0;
        while(row > start * 2 && col > start * 2) {
            int endRow = row - start;
            int endCol = col - start;
            for (int i = start; i < endCol; ++i) {
                res.push_back(matrix[start][i]);
            }
            for (int i = start + 1; i < endRow; ++i) {
                res.push_back(matrix[i][endCol - 1]);
            }
            for (int i = endCol - 2; i >= start && row > 1; --i) {
                res.push_back(matrix[endRow - 1][i]);
            }
            for (int i = endRow - 2; i > start && col > 1; --i) {
                res.push_back(matrix[i][start]);
            }
            start++;
        }
        if (row * col != res.size()) {
            res.pop_back();
        }
        return res;
    }
};

