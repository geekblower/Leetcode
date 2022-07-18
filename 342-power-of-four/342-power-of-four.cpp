class Solution {
public:
    bool isPowerOfFour(int n) {
        /*
        long x = 1;
        while(x<=INT_MAX) {
            if(x == n)
                return true;
            x *= 4;
        }
        return false;
        */
        if(n==1)
            return true;
        if(n%4!=0 || n==0)
            return false;
        return isPowerOfFour(n/4);
    }
};