class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > rotate(row, vector<int>(col));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                rotate[j][col - i - 1] = matrix[i][j];
            }
        }
        matrix = rotate;
    }
};

// in-place
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (row != 0) {
            int col = matrix[0].size();
            for (int i = 0; i < row - 1; ++i) {
                for (int j = 0; j < col - i - 1; ++j) {
                    swap(matrix[i][j], matrix[col - j - 1][row - i - 1]);
                }
            }
            for (int i = 0; i < row / 2; ++i) {
                for (int j = 0; j < col; ++j) {
                    swap(matrix[i][j], matrix[row - i - 1][j]);
                }
            }
        }
    }
};

