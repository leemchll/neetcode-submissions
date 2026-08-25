class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            int currProfit = prices[i] - minPrice;

            minPrice = min(prices[i], minPrice);
            maxProfit = max(currProfit, maxProfit);
        }

        return maxProfit;
    }
};
