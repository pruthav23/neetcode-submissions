class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPrice = prices[0];
        int maxProfit = 0;
        
        for(int r = 1; r < prices.size(); r++){
            int profit = prices[r] - lowestPrice;
            lowestPrice = min(lowestPrice, prices[r]);
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};
