class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<char > > board(n, vector<char>(n, '.'));
        int res = 0;
        total(n, 0, board, res);
        return res;
    }
private:
    void total(int n, int row, vector<vector<char> > &board, int &res) {
        if (row == n) {
            res++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isValid(board, row, i, n)) {
                board[row][i] = 'Q';
                total(n, row + 1, board, res);
            }
            board[row][i] = '.';
        }
    }
    bool isValid(vector<vector<char> > &board, int x, int y, int n) {
        for (int i = x - 1; i >= 0; --i) {
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

