class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0, i = 0;
        
        while(i<n) {
            
            if(s[i] == 'I') {
                if(s[i+1] == 'V') {
                    ans += 4;
                    i += 2;
                    continue;
                } else if (s[i+1] == 'X') {
                    ans += 9;
                    i += 2;
                    continue;
                } 
            }
            
            if(s[i] == 'X') {
                if(s[i+1] == 'L') {
                    ans += 40;
                    i += 2;
                    continue;
                } else if (s[i+1] == 'C') {
                    ans += 90;
                    i += 2;
                    continue;
                } 
            }
            
            if(s[i] == 'C') {
                if(s[i+1] == 'D') {
                    ans += 400;
                    i += 2;
                    continue;
                } else if (s[i+1] == 'M') {
                    ans += 900;
                    i += 2;
                    continue;
                } 
            }
            
            switch(s[i]) {
                case 'I':
                    ans += 1;
                    break;
                    
                case 'V':
                    ans += 5;
                    break;
                    
                case 'X':
                    ans += 10;
                    break;
                    
                case 'L':
                    ans += 50;
                    break;
                    
                case 'C':
                    ans += 100;
                    break;
                    
                case 'D':
                    ans += 500;
                    break;
                    
                case 'M':
                    ans += 1000;
                    break;
            }
            
            i++;
        }
        
        return ans;
    }
};