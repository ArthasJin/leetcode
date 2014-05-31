class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) return 0;
        sort(num.begin(), num.end());
        int res = num[0] + num[1] + num[2];
        for (int i = 0 ; i < num.size(); ++i) {
            int low = i + 1, high = num.size() - 1;
            while(low < high) {
                int sum = num[i] + num[low] + num[high];
                if (sum > target) {
                    high--;
                } else if (sum < target) {
                    low++;
                } else {
                    return sum;
                }
                if (abs(target - sum) < abs(target - res)) {
                    res = sum;
                }
            }
        }
        return res;
    }
};

