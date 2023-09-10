class Solution {
public:
    int solveRec(vector<int> &v, int i, int j) {
        if(i+1 == j) {
            return 0;
        }
        
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++) {
            ans = min(ans, v[i]*v[j]*v[k] + solveRec(v, i, k) + solveRec(v, k, j));
        }
        
        return ans;
    }
    
    int solveMem(vector<vector<int>> &dp, vector<int> &v, int i, int j) {
        if(i+1 == j) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++) {
            ans = min(ans, v[i]*v[j]*v[k] + solveMem(dp, v, i, k) + solveMem(dp, v, k, j));
        }
        
        dp[i][j] = ans;
        return ans;
    }
    
    int solveTab(vector<int> &v) {
        int size = v.size();
        vector<vector<int>> dp(size, vector<int>(size, 0)); 

        for(int i=size-1; i>=0; i--) {
            for(int j=i+2; j<size; j++) {
                
                int ans = INT_MAX;
                for(int k=i+1; k<j; k++) {
                    ans = min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                }

                dp[i][j] = ans;
                
            }
        }
        
        return dp[0][size-1];
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int size = values.size();
        
        // return solveRec(values, 0, size-1);
        
        // vector<vector<int>> dp(size, vector<int>(size, -1));
        // return solveMem(dp, values, 0, size-1);
        
        return solveTab(values);
    }
};