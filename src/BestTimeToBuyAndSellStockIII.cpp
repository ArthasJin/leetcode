class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() > 1) {
            vector<int> left(prices.size(), 0);
            vector<int> right(prices.size(), 0);
            int profit = 0, minPrice = INT_MAX;
            for (int i = 0; i < prices.size(); ++i) {
                minPrice = min(minPrice, prices[i]);
                profit = max(profit, prices[i] - minPrice);
                left[i] = profit;
            }
            int maxPrice = INT_MIN;
            profit = 0;
            for (int i = prices.size() - 1; i >= 0; --i) {
                maxPrice = max(maxPrice, prices[i]);
                profit = max(profit, maxPrice - prices[i]);
                right[i] = profit;
            }
            profit = 0;
            for (int i = 0; i < prices.size(); ++i) {
                profit = max(left[i] + right[i], profit);
            }
            return profit;
        }
        return 0;
    }
};

