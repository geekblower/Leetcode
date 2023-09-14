class Solution {
public:
    int solveRec(int dices, int faces, int target) {
        // Base cases
        if(target < 0) return 0;
        if(dices == 0 && target != 0) return 0;
        if(dices != 0 && target == 0) return 0;
        if(dices == 0 && target == 0) return 1;
        
        int ans = 0;
        for(int i=1; i<=faces; i++) {
            ans = (ans + solveRec(dices-1, faces, target-i)) % 1000000007;
        }
        
        return ans;
    }
    
    int solveMem(vector<vector<int>> &dp, int dices, int faces, int target) {
        // Base cases
        if(target < 0) return 0;
        if(dices == 0 && target != 0) return 0;
        if(dices != 0 && target == 0) return 0;
        if(dices == 0 && target == 0) return 1;
        
        if(dp[dices][target] != -1) {
            return dp[dices][target];
        }
        
        int ans = 0;
        for(int i=1; i<=faces; i++) {
            ans = (ans + solveMem(dp, dices-1, faces, target-i)) % 1000000007;
        }
        
        dp[dices][target] = ans;
        return dp[dices][target];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        // return solveRec(n, k, target);    
        
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return solveMem(dp, n, k, target);
    }
};