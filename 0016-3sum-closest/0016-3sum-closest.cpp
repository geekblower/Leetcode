class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int total = -1;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++) {
            int start = i+1;
            int end = nums.size() - 1;
            
            while(start < end) {
                int sum = nums[i]+nums[start]+nums[end];

                if(sum == target) {
                    return sum;
                }

                if(abs(sum-target) < diff) {
                    diff = abs(sum-target);
                    total = sum;
                }
                
                if(sum < target) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        
        return total;
    }
};