class Solution {
public:
    int solveSpc(vector<int>& prices, int n, int fee) {
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        
        for(int index=n-1; index>=0; index--) {
            for(int buy=0; buy<=1; buy++) {
                
                int profit = 0;
                if(buy) {
                    int buyStock = (-prices[index] + next[0]);
                    int skipStock = next[1];

                    profit = max(buyStock, skipStock);
                } else {
                    int sellStock = (prices[index] + next[1] - fee);
                    int skipStock = next[0];

                    profit = max(sellStock, skipStock);
                }

                curr[buy] = profit;
                
            }
            next = curr;
        }
        
        return next[1];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        return solveSpc(prices, prices.size(), fee);
    }
};