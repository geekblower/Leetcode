class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.length();
        int i = 0;
        
        while((s[i]<'0' || s[i]>'9') && i<n)
                i++;
        
        int num = s[i] - '0';
        i++;
        if(s[i]>='0' && s[i]<='9' && i<n) {
            num *= 10;
            num += (s[i] - '0');
        }
        i++;
        
        for(; i<n; i++) {
            while((s[i]<'0' || s[i]>'9') && i<n)
                i++;
            
            if(i>=n)
                break;
            
            int newNum = s[i] - '0';
            i++;
            if(s[i]>='0' && s[i]<='9' && i<n) {
                newNum *= 10;
                newNum += (s[i] - '0');
            }
            
            if(newNum <= num)
                return false;
            else
                num = newNum;
        }
        
        return true;
    }
};