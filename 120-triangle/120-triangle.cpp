class Solution {
public:
    int helper(vector<vector<int>> &triangle, int i, int j, int m, vector<vector<int>>& dp) {
        if (i == m -1)
            return triangle[i][j];
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int op1 = triangle[i][j] + helper(triangle, i+1, j, m, dp);
        int op2 = triangle[i][j] + helper(triangle, i+1, j+1, m, dp);
        
        return dp[i][j] = min(op1, op2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int i=0, j=0;
        int m = triangle.size();
        vector<vector<int>> dp(m+1, vector<int> (m+1, -1));
        
        return helper(triangle, i, j, m, dp);
    }
};