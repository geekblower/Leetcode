class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int pdt1 = nums[0] * nums[1];
        int pdt2 = nums[nums.size()-1] * nums[nums.size()-2];

        return pdt2-pdt1;
    }
};