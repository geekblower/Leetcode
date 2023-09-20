class Solution {
public:
    int solveSpc(string s1, string s2) {
        vector<int> curr(s2.length()+1, 0);
        vector<int> next(s2.length()+1, 0);

        
        for(int i=s1.length()-1; i>=0; i--) {
            for(int j=s2.length()-1; j>=0; j--) {
                if(s1[i] == s2[j]) {
                    curr[j] = 1 + next[j+1];
                } else {
                    curr[j] = max(next[j], curr[j+1]);
                }
            }
            next = curr;
        }
        
        return next[0];
    }
    
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
            
        return solveSpc(s, rev);    
    }
};