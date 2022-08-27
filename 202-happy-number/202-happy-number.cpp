class Solution {
public:
    long long power(int n) {
        if(n<10)
            return n*n;
        return ((n%10) * (n%10)) + power(n/10);
    }
    
    bool isHappy(int n) {
        while(1) {
            if(n==89)
                return false;

            if(n==1)
                return true;

            n = power(n);
        }
    }
};