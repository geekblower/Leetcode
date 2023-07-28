class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        
        int sum = 0;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++) {
            if(i==nums.size()-1 || nums[i] != nums[i+1]) {
                sum += nums[i];
            }

            while(i<nums.size()-1 && nums[i] == nums[i+1]) {
                i++;
            }
        }

        return sum;

    }
};