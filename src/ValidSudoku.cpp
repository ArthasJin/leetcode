class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() > 0) {
            unordered_set<char> row, col, block;
            for (int i = 0; i < 9; ++i) {
                row.clear();
                col.clear();
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] != '.') {
                        if (row.find(board[i][j]) != row.end()) {
                            return false;
                        } else {
                            row.insert(board[i][j]);
                        }
                    }
                    if (board[j][i] != '.') {
                        if (col.find(board[j][i]) != col.end()) {
                            return false;
                        } else {
                            col.insert(board[j][i]);
                        }
                    }
                }
            }
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    block.clear();
                    for (int m = 0; m < 3; ++m) {
                        for (int n = 0; n < 3; ++n) {
                            int x = m + i * 3;
                            int y = n + j * 3;
                            if (board[x][y] != '.') {
                                if (block.find(board[x][y]) != block.end()) {
                                    return false;
                                } else {
                                    block.insert(board[x][y]);
                                }
                            }
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }
};

// alternative
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i) {
            int row[10] = { 0 };
            int col[10] = { 0 };
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (row[board[i][j] - '0']) {
                        return false;
                    } else {
                        row[board[i][j] - '0'] = 1;
                    }
                }
                if (board[j][i] != '.') {
                    if (col[board[j][i] - '0']) {
                        return false;
                    } else {
                        col[board[j][i] - '0'] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int block[10] = { 0 };
                for (int m = i * 3; m < i * 3 + 3; ++m) {
                    for (int n = j * 3; n < j * 3 + 3; ++n) {
                        if (board[m][n] != '.') {
                            if (block[board[m][n] - '0']) {
                                return false;
                            } else {
                                block[board[m][n] - '0'] = 1;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

