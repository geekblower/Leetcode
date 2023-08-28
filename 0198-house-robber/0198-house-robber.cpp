class Solution {
public:
    int rob(vector<int>& nums) {
        int prev0 = 0;
        int prev1 = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            int inc = nums[i] + prev0;
            int exc = prev1;
            
            int curr = max(inc, exc);
            
            prev0 = prev1;
            prev1 = curr;
        }
        
        return max(prev0, prev1);
    }
};