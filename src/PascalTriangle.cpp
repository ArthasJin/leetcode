class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        for (int i = 0; i < numRows; ++i) {
            vector<int> entry;
            for (int j = 0; j < i + 1; ++j) {
                entry.push_back(pascal(i, j));
            }
            res.push_back(entry);
        }
        return res;
    }
private:
    map<pair<int, int>, int> memo;
    int pascal(int row, int col) {
        pair<int, int> p = make_pair(row, col);
        if (memo.find(p) != memo.end()) {
            return memo[p];
        }
        if (row == 0 || col == 0 || row == col) {
            return 1;
        } else {
            pair<int, int> p1 = make_pair(row - 1, col - 1);
            pair<int, int> p2 = make_pair(row - 1, col);
            memo[p] = pascal(row - 1, col - 1) + pascal(row - 1, col);
            return memo[p];
        }
    }
};

