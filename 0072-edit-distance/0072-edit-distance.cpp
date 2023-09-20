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
    
    int solveTab(string str1, string str2, int len1, int len2) {
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        for(int j=0; j<len2; j++) {
            dp[len1][j] = len2 - j;
        }
        
        for(int i=0; i<len1; i++) {
            dp[i][len2] = len1 - i;
        }
        
        for(int i=len1-1; i>=0; i--) {
            for(int j=len2-1; j>=0; j--) {
                int ans = 0;
        
                if(str1[i] == str2[j]) {
                    ans = dp[i+1][j+1];
                } else {
                    int insAns = 1 + dp[i][j+1];
                    int delAns = 1 + dp[i+1][j];
                    int repAns = 1 + dp[i+1][j+1];

                    ans = min(insAns, min(delAns, repAns));
                }

                dp[i][j] = ans;
            }
        }
        
        return dp[0][0];
    }
    
    int solveSpc(string str1, string str2, int len1, int len2) {
        if(len1 == 0) return len2;
        if(len2 == 0) return len1;
        
        vector<int> curr(len2+1, 0);
        vector<int> next(len2+1, 0);
        
        for(int j=0; j<len2; j++) {
            next[j] = len2 - j;
        }
        
        for(int i=len1-1; i>=0; i--) {
            for(int j=len2-1; j>=0; j--) {
                curr[len2] = len1 - i;
                int ans = 0;
        
                if(str1[i] == str2[j]) {
                    ans = next[j+1];
                } else {
                    int insAns = 1 + curr[j+1];
                    int delAns = 1 + next[j];
                    int repAns = 1 + next[j+1];

                    ans = min(insAns, min(delAns, repAns));
                }

                curr[j] = ans;
            }
            next = curr;
        }
        
        return next[0];
    }
    
    int minDistance(string word1, string word2) {
        // return solveRec(word1, word2, 0, 0);
        
        // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        // return solveMem(dp, word1, word2, 0, 0);
        
        // return solveTab(word1, word2, word1.length(), word2.length());
        
        return solveSpc(word1, word2, word1.length(), word2.length());
    }
};