class Solution {
public:
    int solveRec(int n) {
        if(n <= 1) return 1;
        
        int ans = 0;
        
        // i -> root node
        for(int i=1; i<=n; i++) {
            ans += solveRec(i-1) * solveRec(n-i);
        }
        
        return ans;
    }
    
    int solveMem(vector<int> &dp, int n) {
        if(n <= 1) return 1;
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int ans = 0;
        
        // i -> root node
        for(int i=1; i<=n; i++) {
            ans += solveMem(dp, i-1) * solveMem(dp, n-i);
        }
        
        dp[n] = ans;
        return dp[n];
    }
    
    int solveTab(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        
        // i -> number of nodes
        for(int i=2; i<=n; i++) {
            // j -> root node
            for(int j=1; j<=i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        
        return dp[n];
    }
    
    int numTrees(int n) {
        // return solveRec(n);
        
        // vector<int> dp(n+1, -1);
        // return solveMem(dp, n);
        
        return solveTab(n);
    }
};