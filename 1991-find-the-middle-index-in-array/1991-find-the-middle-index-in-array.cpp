class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int sum[10000] = {0};
        
        sum[0] = nums[0];
        
        for(int i=1; i<n; i++)
            sum[i] = sum[i-1] + nums[i];
        
        if((sum[n-1]-sum[0]) == 0)
            return 0;
        
        for(int i=1; i<n; i++) {
            if(sum[i-1] == (sum[n-1]-sum[i]))
                return i;
        }
        
        return -1;
    }
};