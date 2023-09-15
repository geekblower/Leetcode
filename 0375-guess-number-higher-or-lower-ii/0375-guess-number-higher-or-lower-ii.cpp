class Solution {
public:
    int solveRec(int start, int end) {
        if(start >= end) return 0;
        
        int maxi = INT_MAX;
        for(int i=start; i<=end; i++) {
            maxi = min(maxi, i + max(solveRec(start, i-1), solveRec(i+1, end)));
        }
        
        return maxi;
    }
    
    int solveMem(vector<vector<int>> &dp, int start, int end) {
        if(start >= end) return 0;
        
        if(dp[start][end] != -1) {
            return dp[start][end];
        }
        
        int maxi = INT_MAX;
        for(int i=start; i<=end; i++) {
            maxi = min(maxi, i + max(solveMem(dp, start, i-1), solveMem(dp, i+1, end)));
        }
        
        dp[start][end] = maxi;
        return dp[start][end];
    }
    
    int solveTab(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int start=n; start>=1; start--) {
            for(int end=start; end<=n; end++) {
                if(end == start) continue;
                int maxi = INT_MAX;
                
                for(int i=start; i<=end; i++) {
                    maxi = min(maxi, i + max(dp[start][i-1], dp[i+1][end]));
                }

                dp[start][end] = maxi;
            }
        }
        
        return dp[1][n];
    }
    
    int getMoneyAmount(int n) {
        // return solveRec(1, n);   
        
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMem(dp, 1, n);
        
        return solveTab(n);
    }
};