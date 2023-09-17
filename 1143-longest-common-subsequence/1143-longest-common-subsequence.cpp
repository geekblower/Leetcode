class Solution {
public:
    int solveRec(string s1, string s2, int i, int j) {
        if(i==s1.length() || j==s2.length()) return 0;
        
        if(s1[i] == s2[j]) {
            return 1 + solveRec(s1, s2, i+1, j+1);
        }
        
        return max(solveRec(s1, s2, i+1, j), solveRec(s1, s2, i, j+1));
    }
    
    int solveMem(vector<vector<int>> &dp, string s1, string s2, int i, int j) {
        if(i==s1.length() || j==s2.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) {
            return 1 + solveMem(dp, s1, s2, i+1, j+1);
        }
        
        dp[i][j] = max(solveMem(dp, s1, s2, i+1, j), solveMem(dp, s1, s2, i, j+1));
        return dp[i][j];
    }
    
    int solveTab(string s1, string s2) {
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
        
        for(int i=s1.length()-1; i>=0; i--) {
            for(int j=s2.length()-1; j>=0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = 1 + solveMem(dp, s1, s2, i+1, j+1);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        // return solveRec(text1, text2, 0, 0);    
        
        // vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        // return solveMem(dp, text1, text2, 0, 0);
        
        return solveTab(text1, text2);
    }
};