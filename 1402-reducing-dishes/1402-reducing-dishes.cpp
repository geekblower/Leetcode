class Solution {
public:
    int solveRec(vector<int> &sat, int index, int time) {
        if(index == sat.size()) {
            return 0;
        }
        
        int include = sat[index] * (time+1) + solveRec(sat, index+1, time+1);
        int exclude = solveRec(sat, index+1, time);
        
        return max(include, exclude);
    }
    
    int solveMem(vector<vector<int>> &dp, vector<int> &sat, int index, int time) {
        if(index == sat.size()) {
            return 0;
        }
        
        if(dp[index][time] != -1) {
            return dp[index][time];
        }
        
        int include = sat[index] * (time+1) + solveMem(dp, sat, index+1, time+1);
        int exclude = solveMem(dp, sat, index+1, time);
        
        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }
    
    int solveTab(vector<int> &sat, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int index=n-1; index>=0; index--) {
            for(int time=index; time>=0; time--) {
                int include = sat[index] * (time+1) + dp[index+1][time+1];
                int exclude = dp[index+1][time];

                dp[index][time] = max(include, exclude);
            }
        }
        
        return dp[0][0];
    }
    
    int solveSpc(vector<int> &sat, int n) {
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int index=n-1; index>=0; index--) {
            for(int time=index; time>=0; time--) {
                int include = sat[index] * (time+1) + next[time+1];
                int exclude = next[time];

                curr[time] = max(include, exclude);
            }
            
            next = curr;
        }
        
        return next[0];
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        // Sorting array
        sort(satisfaction.begin(), satisfaction.end());
        
        // return solveRec(satisfaction, 0, 0);    
        
        int n = satisfaction.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solveMem(dp, satisfaction, 0, 0);
        
        // return solveTab(satisfaction, n);
        
        return solveSpc(satisfaction, n);
    }
};