class Solution {
public:
    int ar[45];
    
    int climbStairs(int n) {
        memset(ar, -1, sizeof(ar));
        return pb(n);
    }
    
    int pb(int n) {
        if(n==1 || n==2)
            return n;
        
        if(ar[n-1] != -1)
            return ar[n-1];
        
        return ar[n-1] = pb(n-1) + pb(n-2);
    }
};