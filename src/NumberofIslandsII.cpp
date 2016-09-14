class Solution {
private:
    int findIsland(vector<int>& nodes, int id) {
        while (id != nodes[id]) {
            id = nodes[id];
        }
        return id;
    }
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        if (positions.size() == 0) {
            return vector<int>();
        }
        vector<int> res;
        vector<int> nodes(m * n, -1);
        vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        int count = 0;
        for (int i = 0; i < positions.size(); ++i) {
            pair<int, int> pos = positions[i];
            int rootIndex = pos.first * n + pos.second;
            nodes[rootIndex] = rootIndex;
            count++;
            for (pair<int, int> d : dir) {
                int x = pos.first + d.first;
                int y = pos.second + d.second;
                int nextIndex = x * n + y;
                if (x < 0 || x >= m || y < 0 || y >= n || nodes[nextIndex] == -1) {
                    continue;
                }
                int nextRootIndex = findIsland(nodes, nextIndex);
                if (nextRootIndex != rootIndex) {
                    nodes[rootIndex] = nextRootIndex;
                    rootIndex = nextRootIndex;
                    count--;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};

