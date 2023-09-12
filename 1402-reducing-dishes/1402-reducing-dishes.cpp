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
    
    int maxSatisfaction(vector<int>& satisfaction) {
        // Sorting array
        sort(satisfaction.begin(), satisfaction.end());
        
        // return solveRec(satisfaction, 0, 0);    
        
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solveMem(dp, satisfaction, 0, 0);
    }
};