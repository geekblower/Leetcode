class Solution {
public:
    long long max(long long a, long long b) {return (a>b) ? a : b;}
    
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        vector<int> prefix_max(nums);
        vector<int> suffix_max(nums);
        
        for(int i=1; i<n; i++) {
            prefix_max[i] = max(prefix_max[i], prefix_max[i-1]);
        }
        
        for(int i=n-2; i>=0; i--) {
            suffix_max[i] = max(suffix_max[i], suffix_max[i+1]);
        }
        
        for(int i=1; i<n-1; i++) {
            long long temp = (long long) (prefix_max[i-1] - nums[i]) * (suffix_max[i+1]);
            ans = max(ans, temp);
        }
        
        return ans;
        
    }
};