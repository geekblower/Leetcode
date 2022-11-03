class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0;
        int maximum_sum = INT_MIN;
        int n = nums.size(); 

        for(int i=0; i<n; i++) {
            current_sum += nums[i];
            maximum_sum = max(maximum_sum,current_sum);

            if(current_sum < 0) 
                current_sum = 0;
        }

        return maximum_sum;
    }
};