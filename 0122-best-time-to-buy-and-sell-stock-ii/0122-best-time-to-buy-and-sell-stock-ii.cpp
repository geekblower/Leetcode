class Solution {
public:
    int solveRec(vector<int>& prices, int index, int buy) {
        if(index == prices.size()) return 0;
        
        int profit = 0;
        if(buy) {
            int buyStock = (-prices[index] + solveRec(prices, index+1, 0));
            int skipStock = solveRec(prices, index+1, 1);
            
            profit = max(buyStock, skipStock);
        } else {
            int sellStock = (prices[index] + solveRec(prices, index+1, 1));
            int skipStock = solveRec(prices, index+1, 0);
            
            profit = max(sellStock, skipStock);
        }
        
        return profit;
    }
    
    int solveMem(vector<vector<int>> &dp, vector<int>& prices, int index, int buy) {
        if(index == prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        
        int profit = 0;
        if(buy) {
            int buyStock = (-prices[index] + solveMem(dp, prices, index+1, 0));
            int skipStock = solveMem(dp, prices, index+1, 1);
            
            profit = max(buyStock, skipStock);
        } else {
            int sellStock = (prices[index] + solveMem(dp, prices, index+1, 1));
            int skipStock = solveMem(dp, prices, index+1, 0);
            
            profit = max(sellStock, skipStock);
        }
        
        dp[index][buy] = profit;
        return dp[index][buy];
    }
    
    int maxProfit(vector<int>& prices) {
        // return solveRec(prices, 0, 1);
        
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solveMem(dp, prices, 0, 1);
    }
};