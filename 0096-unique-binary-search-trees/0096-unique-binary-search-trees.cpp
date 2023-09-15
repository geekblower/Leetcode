class Solution {
public:
    int solveRec(int n) {
        if(n <= 1) return 1;
        
        int ans = 0;
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
        for(int i=1; i<=n; i++) {
            ans += solveMem(dp, i-1) * solveMem(dp, n-i);
        }
        
        dp[n] = ans;
        return dp[n];
    }
    
    int numTrees(int n) {
        // return solveRec(n);
        
        vector<int> dp(n+1, -1);
        return solveMem(dp, n);
    }
};