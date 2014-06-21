class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() > 0) {
            int tank = 0, i = 0, j = 0, n = gas.size();
            while(i < n) {
                if (j > n) {
                    return i;
                }
                int net = 0;
                if (i + j >= n) {
                    net = gas[i + j - n] - cost[i + j - n];
                } else {
                    net = gas[i + j] - cost[i + j];
                }
                if (tank + net < 0) {
                    j++;
                    i = i + j;
                    tank = 0;
                    j = 0;
                } else {
                    tank += net;
                    j++;
                }
            }
        }
        return -1;
    }
};

