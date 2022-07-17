class Solution {
public:
    bool isPowerOfTwo(int n) {
        long pow = 1;
        int i = 31;
        
        while(i) {
            if(n == pow)
                return true;
            pow *= 2;
            i--;
        }
        
        return false;
    }
};