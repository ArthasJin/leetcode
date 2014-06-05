class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() > 0) {
            int row = board.size();
            int col = board[0].size();
            queue<pair<int, int> > q1;
            for (int i = 0; i < row; ++i) {
                if (board[i][0] == 'O') {
                    q1.push(make_pair(i, 0));
                }
                if (board[i][col - 1] == 'O') {
                    q1.push(make_pair(i, col - 1));
                }
            }
            for (int i = 0; i < col; ++i) {
                if (board[0][i] == 'O') {
                    q1.push(make_pair(0, i));
                }
                if (board[row - 1][i] == 'O') {
                    q1.push(make_pair(row - 1, i));
                }
            }
            while(!q1.empty()) {
                pair<int, int> node = q1.front();
                q1.pop();
                int x = node.first;
                int y = node.second;
                board[x][y] = '*';
                if (y - 1 >= 0 && board[x][y - 1] == 'O') {
                    q1.push(make_pair(x, y - 1));
                }
                if (y + 1 < col && board[x][y + 1] == 'O') {
                    q1.push(make_pair(x, y + 1));
                }
                if (x + 1 < row && board[x+ 1][y] == 'O') {
                    q1.push(make_pair(x + 1, y));
                }
                if (x - 1 >= 0 && board[x - 1][y] == 'O') {
                    q1.push(make_pair(x - 1, y));
                }
            }
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (board[i][j] == 'O') {
                        board[i][j] = 'X';
                    } else if (board[i][j] == '*') {
                        board[i][j] = 'O';
                    }
                }
            }
        }
    }
};

