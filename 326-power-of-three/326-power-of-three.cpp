class Solution {
public:
    bool isPowerOfThree(int n) {
        long x = 1;
        
        while(x <= INT_MAX) {
            if(x==n)
                return true;
            x *= 3;
        }
        
        return false;
    }
};