class Solution{
public:
    int maxProfit(vector<int>&prices) {
     int l = prices[0];
        int p = prices[0];
        int sum = 0;
        prices.push_back(INT_MIN);
        for (int i = 1; i < prices.size() - 1; i++)
        {

           l = min(l,prices[i]);
           if (prices[i] > prices[i + 1])
           {
               sum = sum + prices[i] - l;
               l = prices[i];
           }
        }
        return sum;
    }
};