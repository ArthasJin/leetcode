class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() > 0) {
            vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size()));
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[i].size(); ++j) {
                    if (find(board, i, j, 0, word, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    bool find(vector<vector<char> > &board, int x, int y, int index, string &word, vector<vector<bool> > &visited) {
        int row = board.size();
        int col = board[0].size();
        if (index == word.length()) {
            return true;
        }
        if (x < 0 || x >= row || y < 0 || y >= col) {
            return false;
        }
        if (visited[x][y]) {
            return false;
        }
        visited[x][y] = true;
        bool res = false;
        if (board[x][y] == word[index]) {
            res = find(board, x - 1, y, index + 1, word, visited) ||
                  find(board, x + 1, y, index + 1, word, visited) ||
                  find(board, x, y - 1, index + 1, word, visited) ||
                  find(board, x, y + 1, index + 1, word, visited);
        }
        visited[x][y] = false;
        return res;
    }
};

