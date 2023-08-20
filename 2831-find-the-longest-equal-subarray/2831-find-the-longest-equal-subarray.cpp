class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int maxCount = 0;
        int back = 0;
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = 0;
            }

            // adding into map
            map[nums[i]]++;

            // count max freq
            if(map[nums[i]] > maxCount) maxCount = map[nums[i]];

            if((i - back+1 - maxCount) > k){
                map[nums[back]] -= 1;
                back++;
            }
            
            if(maxCount > ans) ans = maxCount;
        }
        
        return ans;
    }
};