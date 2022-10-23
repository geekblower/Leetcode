class Solution {
public:
    int countOdds(int low, int high) {
        /*
        int ans = 0;
        
        for(; low<=high; low++) {
            if(low&1)
                ans++;
        }
        
        return ans;
        */
        
        int ans = (high-low)/2;
        
        if(low&1 || high&1)
            ans += 1;
        
        return ans;
    }
};