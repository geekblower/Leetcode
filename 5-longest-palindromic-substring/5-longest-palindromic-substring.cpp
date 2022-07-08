class Solution {
public:
    vector<vector<int>> dp;
    
    int isPalindrome(string &s, int i, int j) {
        if(i >= j)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == s[j])
            return dp[i][j] = isPalindrome(s,i+1,j-1);
        
        return dp[i][j] = 0;
    }
    
    string longestPalindrome(string  s) {
        int n = s.length();
        int mx = 0;
        string ans;
        dp.resize(n, vector<int>(n,-1));
        
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                if(isPalindrome(s, i, j)) {
                    if(j-i+1 > mx) {
                        mx = j-i+1;
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        
        return ans;
    }
};