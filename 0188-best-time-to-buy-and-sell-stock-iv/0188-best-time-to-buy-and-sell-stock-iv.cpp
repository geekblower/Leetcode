class Solution {
public:
    int solveSpc(vector<int>& prices, int n, int k) {
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
        
        return solveSpc(prices, n, k);
    }
};