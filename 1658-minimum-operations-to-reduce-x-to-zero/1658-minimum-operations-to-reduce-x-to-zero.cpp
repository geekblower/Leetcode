class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        
        for (int i:nums)
            sum += i;
        
        int target = sum-x;
        int curr_sum = 0, max_len = 0, start = 0;
        bool found = false;
        
        for (int end=0; end<n; end++) {
            curr_sum += nums[end];
            
            while (start<=end && curr_sum>target) {
                curr_sum -= nums[start];
                start += 1;
            }
            
            if (curr_sum == target) {
                found = true;
                max_len = max(max_len, end-start+1);
            }
        }
        
        return found ? n - max_len : -1;
    }
};