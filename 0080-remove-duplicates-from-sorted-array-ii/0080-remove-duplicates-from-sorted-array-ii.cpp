class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++) {
            ans.push_back(nums[i]);
            if(i<nums.size()-1 && nums[i]==nums[i+1]) {
                ans.push_back(nums[i]);
                i++;
            }
            
            while(i<nums.size()-1 && nums[i]==nums[i+1]) {
                count++;
                i++;
            }
        }
        
        nums = ans;
        return nums.size();
    }
};