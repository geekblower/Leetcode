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
    
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        
        // return solve(s, t, 0, 0);
        
        vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));
        return solveMem(dp, s, t, 0, 0);
    }
};