class Solution {
public:
    int solveRec(vector<int> &slices, int index, int endIndex, int n) {
        if(n == 0 || index > endIndex) {
            return 0;
        }
        
        int incl = slices[index] + solveRec(slices, index+2, endIndex, n-1);
        int excl = solveRec(slices, index+1, endIndex, n);
        
        return max(incl, excl);
    }
    
    int solveMem(vector<vector<int>> &dp, vector<int> &slices, int index, int endIndex, int n) {
        if(n == 0 || index > endIndex) {
            return 0;
        }
        
        if(dp[index][n] != -1) {
            return dp[index][n];
        }
        
        int incl = slices[index] + solveMem(dp, slices, index+2, endIndex, n-1);
        int excl = solveMem(dp, slices, index+1, endIndex, n);
        
        dp[index][n] = max(incl, excl);
        return dp[index][n];
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int n = k/3;
        
        // int opt1 = solveRec(slices, 0, k-2, n);
        // int opt2 = solveRec(slices, 1, k-1, n);

        vector<vector<int>> dp1(k, vector<int>(k, -1));
        int opt1 = solveMem(dp1, slices, 0, k-2, n);
        
        vector<vector<int>> dp2(k, vector<int>(k, -1));
        int opt2 = solveMem(dp2, slices, 1, k-1, n);

        return max(opt1, opt2);        
    }
};