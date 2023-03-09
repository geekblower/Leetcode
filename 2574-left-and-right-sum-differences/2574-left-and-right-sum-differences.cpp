class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> sum(nums);
        vector<int> answer(nums.size());
        int temp = 0;
        
        for(int i=1; i<nums.size(); i++) {
            // temp = nums[i];
            sum[i] += sum[i-1];
        }
        
        for(int i=1; i<nums.size(); i++) {
            int left = sum[i-1];
            int right = sum[sum.size()-1] - sum[i];
            answer[i] = abs(left-right);
        }
        
        answer[0] = sum[sum.size()-1] - nums[0];
        
        
        return answer;
    }
};