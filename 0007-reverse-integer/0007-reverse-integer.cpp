class Solution {
public:
    int reverse(int x) {
        int rev=0;
        
        if(x>0) {
            while(x) {
                int dig = x % 10;
                
                if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && dig > 7))
                    return 0;
                
                if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && dig < -8))
                    return 0;
                
                rev = (rev*10) + dig;
                x /= 10;
            }
        } else {
            int temp = abs(x);
            
            while(temp) {
                int dig = temp % 10;
                
                if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && dig > 7))
                    return 0;
                
                if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && dig < -8))
                    return 0;
                
                rev = (rev*10) + dig;
                temp /= 10;
            }
            
            rev *= -1;
        }
        
        return rev;
    }
};