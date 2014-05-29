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

