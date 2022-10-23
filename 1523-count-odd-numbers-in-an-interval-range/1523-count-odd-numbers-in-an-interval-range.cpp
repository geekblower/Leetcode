class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        
        for(; low<=high; low++) {
            if(low&1)
                ans++;
        }
        
        return ans;
    }
};