class Solution {
private:
    int search(int index, vector<vector<int>>& skip, vector<bool>& visited, int left) {
        if (left < 0) {
            return 0;
        }
        if (left == 0) {
            return 1;
        }
        visited[index] = true;
        int res = 0;
        for (int i = 1; i <= 9; ++i) {
            if (!visited[i] && (skip[index][i] == 0 || visited[skip[index][i]])) {
                res += search(i, skip, visited, left - 1);
            }
        }
        visited[index] = false;
        return res;
    }
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10, vector<int>(10));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
        vector<bool> visited(10, false);
        int res = 0;
        for (int i = m; i <= n; ++i) {
            res += search(1, skip, visited, i - 1) * 4;
            res += search(2, skip, visited, i - 1) * 4;
            res += search(5, skip, visited, i - 1);
        }
        return res;
    }
};

