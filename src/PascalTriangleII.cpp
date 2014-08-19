class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 0; i < rowIndex + 1; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                res.push_back(pascal(i, j));
            }
        }
        res.assign(res.end() - rowIndex - 1, res.end());
        return res;
    }
private:
    map<pair<int, int>, int> memo;
    int pascal(int row, int col) {
        pair<int, int> p = make_pair(row, col);
        if (memo.find(p) != memo.end()) {
            return memo[p];
        } else {
            if (row == 0 || col == 0 || row == col) {
                return 1;
            } else {
                memo[p] = pascal(row - 1, col - 1) + pascal(row - 1, col);
                return memo[p];
            }
        }
        return 0;
    }
};

// O(1) space
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res(numRows);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (j == 0 || j == i) {
                    res[i].push_back(1);
                } else {
                    res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
            }
        }
        return res;
    }
};

