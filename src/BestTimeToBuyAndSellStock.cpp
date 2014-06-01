class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() > 1) {
            int minPrice = INT_MAX;
            int profit = INT_MIN;
            for (int i = 0; i < prices.size(); ++i) {
                minPrice = min(minPrice, prices[i]);
                profit = max(profit, prices[i] - minPrice);
            }
            return profit;
        }
        return 0;
    }
};

