class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int z=0, i=0; z<nums.size(); z++) {
            if(nums[z] != 0) {
                swap(nums[z], nums[i]);
                i++;
            }
        }
    }
};