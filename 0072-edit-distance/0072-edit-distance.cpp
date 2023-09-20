class Solution {
public:
    int solveRec(string str1, string str2, int i, int j) {
        if(i == str1.length()) {
            return str2.length() - j;
        }
        
        if(j == str2.length()) {
            return str1.length() - i;
        }
        
        int ans = 0;
        
        if(str1[i] == str2[j]) {
            return solveRec(str1, str2, i+1, j+1);
        } else {
            int insAns = 1 + solveRec(str1, str2, i, j+1);
            int delAns = 1 + solveRec(str1, str2, i+1, j);
            int repAns = 1 + solveRec(str1, str2, i+1, j+1);
            
            ans = min(insAns, min(delAns, repAns));
        }
        
        return ans;
    }
    
    int solveMem(vector<vector<int>> &dp, string str1, string str2, int i, int j) {
        if(i == str1.length()) {
            return str2.length() - j;
        }
        
        if(j == str2.length()) {
            return str1.length() - i;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = 0;
        
        if(str1[i] == str2[j]) {
            return solveMem(dp, str1, str2, i+1, j+1);
        } else {
            int insAns = 1 + solveMem(dp, str1, str2, i, j+1);
            int delAns = 1 + solveMem(dp, str1, str2, i+1, j);
            int repAns = 1 + solveMem(dp, str1, str2, i+1, j+1);
            
            ans = min(insAns, min(delAns, repAns));
        }
        
        dp[i][j] = ans;
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        // return solveRec(word1, word2, 0, 0);
        
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return solveMem(dp, word1, word2, 0, 0);
    }
};