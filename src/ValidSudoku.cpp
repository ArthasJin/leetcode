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

