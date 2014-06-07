class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int> > d(row, vector<int>(col));
        if (obstacleGrid[0][0] == 1) {
            d[0][0] = 0;
        } else {
            d[0][0] = 1;
        }
        for (int i = 1; i < row; ++i) {
            if (obstacleGrid[i][0] != 1) {
                d[i][0] += d[i - 1][0];
            }
        }
        for (int j = 1; j < col; ++j) {
            if (obstacleGrid[0][j] != 1) {
                d[0][j] += d[0][j - 1];
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    d[i][j] = 0;
                } else {
                    d[i][j] += d[i - 1][j] + d[i][j - 1];
                }
            }
        }
        return d[row - 1][col - 1];
    }
};

