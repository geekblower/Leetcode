class Solution {
public:
    bool isPowerOfThree(int n) {
        /*int x = n/3;
        if(n==1)
            return true;
        else if(x*3 == n)
            return isPowerOfThree(x);
        else
            return false;*/
        long x=1;
        while(x <= INT_MAX) {
            if(x==n)
                return true;
            x *= 3;
        }
        return false;
    }
};