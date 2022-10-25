class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i=nums.size()-1; i>1; i--) {
            int x = nums[i-2];
            int y = nums[i-1];
            int z = nums[i];

            if(x+y>z && y+z>x && x+z>y) {
                return x+y+z;
            }
        }
        
        return 0;
    }
};