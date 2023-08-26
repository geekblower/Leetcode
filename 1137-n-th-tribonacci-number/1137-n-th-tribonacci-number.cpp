class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return n;
        
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;
        
        for(int i=3; i<=n; i++) {
            int curr = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = curr;
        }
        
        return t2;
    }
};