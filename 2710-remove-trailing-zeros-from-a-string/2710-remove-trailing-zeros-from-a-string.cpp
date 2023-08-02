class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = 0;
        int i = num.length() - 1;
        
        while(i>=0 && num[i] == '0') {
            i--;
            n++;
        }
        
        return num.substr(0, num.length()-n);
    }
};