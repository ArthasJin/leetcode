class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        if (height.size() > 1) {
            int low = 0, high = height.size() - 1;
            while(low < high) {
                res = max(res, min(height[low], height[high]) * (high - low));
                if (height[low] < height[high]) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        return res;
    }
};

