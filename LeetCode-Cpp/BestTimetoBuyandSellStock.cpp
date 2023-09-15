class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0; // If the array is empty, there's no profit to be made.
        }

        int minPrice = prices[0]; // Initialize the minimum price to the first day's price.
        int maxProfit = 0; // Initialize the maximum profit to 0.

        for (int i = 1; i < prices.size(); ++i) {
            // Update the minimum price if we find a lower price.
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            // Calculate the profit if we sell on this day.
            int currentProfit = prices[i] - minPrice;
            // Update the maximum profit if the current profit is greater.
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }

        return maxProfit;
    }
};
