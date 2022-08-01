class Solution {
public:
    int solution(int i, int j, vector<vector<int>> &dp, int& m, int& n) {
        if(i==m-1 || j==n-1)
            return 1;
        
        if(dp[i][j])
            return dp[i][j];
        
        dp[i][j] = solution(i+1, j, dp, m, n) + solution(i, j+1, dp, m, n);
        
        return dp[i][j];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , 0));
        
        int ans = solution(0, 0, dp, m, n);
        
        return ans;
    }
};