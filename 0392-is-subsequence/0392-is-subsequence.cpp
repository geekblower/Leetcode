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
    
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        return solve(s, t, 0, 0);
    }
};