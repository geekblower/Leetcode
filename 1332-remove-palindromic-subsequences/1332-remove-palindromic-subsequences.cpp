class Solution {
public:
    int removePalindromeSub(string s) {
        if(palindrome(s))
            return 1;
        else
            return 2;
    }
    
    bool palindrome(string s){
        int n = s.size();
        
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1])
                return 0;
        }
        
        return 1;
    }
};