class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        
        bool flag = nums[0] < nums[1];
        
        if(nums[0] == nums[1]) {
            int count = 1;
            while(count < nums.size()) {
                if(nums[count] == nums[count-1]) count++;
                else {
                    flag = nums[count] > nums[count-1];
                    count = -1;
                    break;
                }
            }
            
            if(count != -1) return true;
        }
        
        if(flag) {
            // May Be Increasing Array
            for(int i=1; i<nums.size(); i++) {
                if(nums[i] < nums[i-1]) return false;
            }
        } else {
            // May Be Increasing Array
            for(int i=1; i<nums.size(); i++) {
                if(nums[i] > nums[i-1]) return false;
            }
        }
        
        return true;
    }
};