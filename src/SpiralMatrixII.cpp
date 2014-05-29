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

