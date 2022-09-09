class Solution {
public:
    bool checkString(string s) {
        int i=0, n=s.length();
        
        while(s[i]!='b' && i<n)
            i++;
        
        while(i<n) {
            if(s[i] == 'a')
                return false;
            i++;
        }
        
        return true;
    }
};