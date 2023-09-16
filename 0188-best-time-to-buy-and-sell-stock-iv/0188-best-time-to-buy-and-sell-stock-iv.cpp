class Solution {
public:
    int solveRec(vector<int>& prices, int n, int k, int index, int operations) {
        if(index == n) return 0;
        if(operations == 2*k) return 0;
        
        int profit = 0;
        if(operations%2 == 0) {
            int buyStock = (-prices[index] + solveRec(prices, n, k, index+1, operations+1));
            int skipStock = solveRec(prices, n, k, index+1, operations);
            
            profit = max(buyStock, skipStock);
        } else {
            int sellStock = (prices[index] + solveRec(prices, n, k, index+1, operations+1));
            int skipStock = solveRec(prices, n, k, index+1, operations);
            
            profit = max(sellStock, skipStock);
        }
        
        return profit;
    }
    
    int solveMem(vector<vector<int>> &dp, vector<int>& prices, int n, int k, int index, int operations) {
        if(index == n) return 0;
        if(operations == 2*k) return 0;
        if(dp[index][operations] != -1) return dp[index][operations];
        
        int profit = 0;
        if(operations%2 == 0) {
            int buyStock = (-prices[index] + solveMem(dp, prices, n, k, index+1, operations+1));
            int skipStock = solveMem(dp, prices, n, k, index+1, operations);
            
            profit = max(buyStock, skipStock);
        } else {
            int sellStock = (prices[index] + solveMem(dp, prices, n, k, index+1, operations+1));
            int skipStock = solveMem(dp, prices, n, k, index+1, operations);
            
            profit = max(sellStock, skipStock);
        }
        
        dp[index][operations] = profit;
        return dp[index][operations];
    }
    
    int solveTab(vector<int>& prices, int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        
        for(int index=n-1; index>=0; index--) {
            for(int operations=0; operations<2*k; operations++) {
                
                int profit = 0;
                if(operations%2 == 0) {
                    int buyStock = (-prices[index] + dp[index+1][operations+1]);
                    int skipStock = dp[index+1][operations];

                    profit = max(buyStock, skipStock);
                } else {
                    int sellStock = (prices[index] + dp[index+1][operations+1]);
                    int skipStock = dp[index+1][operations];

                    profit = max(sellStock, skipStock);
                }

                dp[index][operations] = profit;
                
            }
        }
        
        return dp[0][0];
    }
    
    int solveOptimised(vector<int>& prices, int n, int k) {
        vector<vector<int>> curr(2, vector<int>(k+1,0));
        vector<vector<int>> next(2, vector<int>(k+1,0));
        
        for(int index=n-1; index>=0; index--) {
            for(int buy=0; buy<=1; buy++) {
                
                for(int limit=1; limit<=k; limit++) {
                    int profit = 0;
                    if(buy) {
                        int buyStock = (-prices[index] + next[0][limit]);
                        int skipStock = next[1][limit];

                        profit = max(buyStock, skipStock);
                    } else {
                        int sellStock = (prices[index] + next[1][limit-1]);
                        int skipStock = next[0][limit];

                        profit = max(sellStock, skipStock);
                    }

                    curr[buy][limit] = profit;
                }         
            }
            next = curr;
        }
        
        return next[1][k];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        // return solveOptimised(prices, n, k);
        
        // return solveRec(prices, n, k, 0, 0);
        
        // vector<vector<int>> dp(n, vector<int>(2*k, -1));
        // return solveMem(dp, prices, n, k, 0, 0);
        
        return solveTab(prices, n, k);
    }
};