class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        
        for(int i=0; i<nums.size(); i++) {
            if(!nums[i])
                return 0;
            
            ans *= (nums[i]>0) ? 1 : -1;
        }
        
        return ans;
    }
};