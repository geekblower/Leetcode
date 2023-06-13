class Solution {
public:
    int myAtoi(string s) {
        int ans = 0, sign = 1, i = 0;
        
        while(s[i] == ' ')
            i++;
        
        if(s[i] == '-') {
            sign = -1;
            i++;
        } else if(s[i] == '+') {
            sign = 1;
            i++;
        }
        
        while(i<s.length() && (s[i] >= '0' && s[i] <= '9')) {
            if((ans>INT_MAX/10) || (ans==INT_MAX/10 && s[i]>'7'))
                return sign == 1 ? INT_MAX : INT_MIN;
            
            int x = s[i] - 48;
                ans = ans*10 + x;
            
            i++;
        }
        
        return ans*sign;
    }
};