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
    
    int solveTab(int dices, int faces, int target) {
        vector<vector<int>> dp(dices+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        
        for(int d=1; d<=dices; d++) {
            for(int t=1; t<=target; t++) {
                
                int ans = 0;
                for(int i=1; i<=faces; i++) {
                    if(t-i >= 0)
                        ans = (ans + dp[d-1][t-i]) % 1000000007;
                }
                dp[d][t] = ans;
                
            }
        }
        
        return dp[dices][target];
    }
    
    int solveSpc(int dices, int faces, int target) {
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        
        prev[0] = 1;
        
        for(int d=1; d<=dices; d++) {
            for(int t=1; t<=target; t++) {
                
                int ans = 0;
                for(int i=1; i<=faces; i++) {
                    if(t-i >= 0)
                        ans = (ans + prev[t-i]) % 1000000007;
                }
                curr[t] = ans;
                
            }
            
            prev = curr;
        }
        
        return prev[target];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        // return solveRec(n, k, target);    
        
        // vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        // return solveMem(dp, n, k, target);
        
        // return solveTab(n, k, target);
        
        return solveSpc(n, k, target);
    }
};