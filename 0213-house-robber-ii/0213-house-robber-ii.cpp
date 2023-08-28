class Solution {
public:
    int solveSpc(vector<int> &nums, int index, int n) {
        if(index >= nums.size()) return 0;
        
        int prev0 = 0;
        int prev1 = nums[index];
        
        for(int i=index+1; i<n; i++) {
            int inc = prev0 + nums[i];
            int exc = prev1;
            
            int curr = max(inc, exc);
            
            prev0 = prev1;
            prev1 = curr;
        }
        
        return max(prev0, prev1);
    }
    
    int rob(vector<int>& nums) {
        int start = solveSpc(nums, 0, nums.size()-1);
        int end = solveSpc(nums, 1, nums.size());
        
        return max(start, end);
    }
};