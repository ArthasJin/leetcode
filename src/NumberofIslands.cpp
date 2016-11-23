class Solution {
private:
    void findIsland(pair<int, int> p, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push(p);
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            if (node.first - 1 >= 0 && grid[node.first - 1][node.second] == '1') {
                q.push(make_pair(node.first - 1, node.second));
                grid[node.first - 1][node.second] = '0';
            }
            if (node.first + 1 < grid.size() && grid[node.first + 1][node.second] == '1') {
                q.push(make_pair(node.first + 1, node.second));
                grid[node.first + 1][node.second] = '0';
            }
            if (node.second - 1 >= 0 && grid[node.first][node.second - 1] == '1') {
                q.push(make_pair(node.first, node.second - 1));
                grid[node.first][node.second - 1] = '0';
            }
            if (node.second + 1 < grid[0].size() && grid[node.first][node.second + 1] == '1') {
                q.push(make_pair(node.first, node.second + 1));
                grid[node.first][node.second + 1] = '0';
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) {
            return 0;
        }
        int col = grid[0].size();
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    findIsland(make_pair(i, j), grid);
                }
            }
        }
        return res;
    }
};

