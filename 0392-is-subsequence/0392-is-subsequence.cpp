class Solution {
public:
    bool solve(string s, string t, int i, int j) {
        if(i > s.length()) return true;
        
        if(j > t.length()) return false;
        
        if(s[i] == t[j]) {
            return solve(s, t, i+1, j+1);
        }
        
        while(j<t.length()) {
            if(t[j] != s[i]) {
                j++;
            } else {
                if(i==s.length()-1)
                    return true;
                else
                    return solve(s, t, i+1, j+1);
            }
        }
        
        return false;
    }
    
    bool solveMem(vector<vector<int>> &dp, string s, string t, int i, int j) {
        if(i > s.length()) return true;
        if(j > t.length()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) {
            return solveMem(dp, s, t, i+1, j+1);
        }
        
        bool ans = false;
        while(j<t.length()) {
            if(t[j] != s[i]) {
                j++;
            } else {
                if(i==s.length()-1)
                    ans = true;
                else
                    ans = solveMem(dp, s, t, i+1, j+1);
                break;
            }
        }
        
        dp[i][j] = ans;
        return dp[i][j];
    }
    
    bool solveTab(string s, string t) {
        vector<bool> dp(s.length(), 0);
        
        int j=t.length()-1;
        for(int i=s.length()-1; i>=0; i--) {
            for(; j>=0; j--) {
                if(s[i] == t[j]) {
                    dp[i] = true;
                    j--;
                    break;
                }
            }
        }
        
        return dp[0];
    }
    
    bool solveOptimised(string s, string t) {
        int j=t.length()-1;

        for(int i=s.length()-1; i>=0; i--) {
            if(j<0) return false;
            
            for(; j>=0; j--) {
                if(s[i] == t[j]) {
                    if(i==0) return true;
                    j--;
                    break;
                }
            }
        }
        
        return false;
    }
    
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        
        // return solve(s, t, 0, 0);
        
        // vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));
        // return solveMem(dp, s, t, 0, 0);
        
        // return solveTab(s, t);
        
        return solveOptimised(s, t);
    }
};