class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length()-1;
        
        while(s[n]==' ')
            n--;
        
        int count = 0;
        
        while(s[n]!=' ') {
            n--;
            count++;
            if(n<0)
                break;
        }
        
        return count;
    }
};