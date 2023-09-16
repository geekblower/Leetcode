class Solution {
public:
    int solveRec(vector<int>& prices, int index, int buy, int limit) {
        if(limit <= 0) return 0;
        if(index == prices.size()) return 0;
        
        int profit = 0;
        if(buy) {
            int buyStock = (-prices[index] + solveRec(prices, index+1, 0, limit));
            int skipStock = solveRec(prices, index+1, 1, limit);
            
            profit = max(buyStock, skipStock);
        } else {
            int sellStock = (prices[index] + solveRec(prices, index+1, 1, limit-1));
            int skipStock = solveRec(prices, index+1, 0, limit);
            
            profit = max(sellStock, skipStock);
        }
        
        return profit;
    }
    
    int solveMem(vector<vector<vector<int>>> dp, vector<int>& prices, int index, int buy, int limit) {
        if(limit <= 0) return 0;
        if(index == prices.size()) return 0;
        if(dp[index][buy][limit] != -1) return dp[index][buy][limit];
        
        int profit = 0;
        if(buy) {
            int buyStock = (-prices[index] + solveMem(dp, prices, index+1, 0, limit));
            int skipStock = solveMem(dp, prices, index+1, 1, limit);
            
            profit = max(buyStock, skipStock);
        } else {
            int sellStock = (prices[index] + solveMem(dp, prices, index+1, 1, limit-1));
            int skipStock = solveMem(dp, prices, index+1, 0, limit);
            
            profit = max(sellStock, skipStock);
        }
        
        dp[index][buy][limit] = profit;
        return dp[index][buy][limit];
    }
    
    int solveTab(vector<int>& prices, int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int index=n-1; index>=0; index--) {
            for(int buy=0; buy<=1; buy++) {
                
                for(int limit=1; limit<=2; limit++) {
                    int profit = 0;
                    if(buy) {
                        int buyStock = (-prices[index] + dp[index+1][0][limit]);
                        int skipStock = dp[index+1][1][limit];

                        profit = max(buyStock, skipStock);
                    } else {
                        int sellStock = (prices[index] + dp[index+1][1][limit-1]);
                        int skipStock = dp[index+1][0][limit];

                        profit = max(sellStock, skipStock);
                    }

                    dp[index][buy][limit] = profit;
                }                
            }
        }
        
        return dp[0][1][2];
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // return solveRec(prices, 0, 1, 2);
        
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solveMem(dp, prices, 0, 1, 2);
        
        return solveTab(prices, n);
    }
};