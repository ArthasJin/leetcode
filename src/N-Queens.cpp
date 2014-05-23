class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return res;
    }
private:
    vector<vector<string> > res;
    void solve(vector<string> &board, int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            board[row][i] = 'Q';
            if (isValid(row, i, n, board)) {
                solve(board, row + 1, n);
            }
            board[row][i] = '.';
        }
    }
    bool isValid(int x, int y, int n, vector<string> &board) {
        for (int i = 0; i < x; ++i) {
            if (board[i][y] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

