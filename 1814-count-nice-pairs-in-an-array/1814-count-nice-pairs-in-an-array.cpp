class Solution {
public:
    int rev(int n) {
        int ans = 0;
        for(;n>0;n/=10) ans = (ans*10) + (n%10);
        return ans;
    }
    
    int countNicePairs(vector<int>& nums) {
        int count = 0;
        
        for(int i=0; i<nums.size(); i++) {
            nums[i] -= rev(nums[i]);
        }
        
        unordered_map<int, int> map;
        
        for(int i=0; i<nums.size(); i++) {
            
            if(map[nums[i]]) {
                count += map[nums[i]];
                map[nums[i]]++;
            } else {
                map[nums[i]] = 1;
            }
            
            count %= (int) 1e9+7;
            
        }
        
        return count;
    }
};