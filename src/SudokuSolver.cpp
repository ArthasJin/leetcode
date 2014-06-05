class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0);
    }
private:
    bool isValid(vector<vector<char> > &board, int x, int y) {
        char ch = board[x][y];
        for (int i = 0; i < 9; ++i) {
            if (y != i && ch == board[x][i]) {
                return false;
            }
            if (x != i && ch == board[i][y]) {
                return false;
            }
        }
        int m = x / 3 * 3;
        int n = y / 3 * 3;
        for (int i = m; i < m + 3; ++i) {
            for (int j = n; j < n + 3; ++j) {
                if (x != i && y != j && ch == board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char> > &board, int index) {
        if (index == 81) {
            return true;
        }
        int row = index / 9;
        int col = index % 9;
        if (board[row][col] == '.') {
            for (int k = 1; k < 10; ++k) {
                board[row][col] = k + '0';
                if (isValid(board, row, col) && solve(board, index + 1)) {
                    return true;
                }
            }
            board[row][col] = '.';
            return false;
        } else {
            return solve(board, index + 1);
        }
    }
};

