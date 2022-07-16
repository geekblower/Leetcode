class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp[100000];
        
        for(int i=0; i<nums.size(); i++) {
            int index = (i+k)%nums.size();
            temp[index] = nums[i];
        }
    
        for(int i=0; i<nums.size(); i++)
            nums[i] = temp[i];
    }
};