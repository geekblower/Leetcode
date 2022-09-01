class Solution {
public:
    int countAsterisks(string s) {
        int n = s.length();
        int count = 0;
        int line = 0;
        
        for(int i=0; i<n; i++) {
            if(s[i] == '|')
                line++;
            
            if(line%2==0 && s[i]=='*')
                count++;
        }
        
        return count;
    }
};