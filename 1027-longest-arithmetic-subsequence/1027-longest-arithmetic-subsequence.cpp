class Solution {
public:
    int solveRec(vector<int>& nums, int index, int diff) {
        if(index < 0) return 0;
        
        int ans = 0;
        for(int j=index-1; j>=0; j--) {
            if(nums[index]-nums[j] == diff) {
                ans = max(ans, 1 + solveRec(nums, j, diff));
            }
        }
        
        return ans;
    }
    
    int solveMem(unordered_map<int, int> dp[], vector<int>& nums, int index, int diff) {
        if(index < 0) return 0;
        
        if(dp[index].count(diff)) {
            return dp[index][diff];
        }
        
        int ans = 0;
        for(int j=index-1; j>=0; j--) {
            if(nums[index]-nums[j] == diff) {
                ans = max(ans, 1 + solveMem(dp, nums, j, diff));
            }
        }
        
        dp[index][diff] = ans;
        return dp[index][diff];
    }
    
    int solveTab(vector<int> &nums, int n) {
        int ans = 0;        
        unordered_map<int, int> dp[n+1];
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int diff = nums[i] - nums[j];
                int cnt = 1;
                
                if(dp[j].count(diff)) {
                    cnt = dp[j][diff];
                }
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        
        return ans;
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) {
            return n;
        }
        
        /*
        unordered_map<int, int> dp[n+1];
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                // ans = max(ans, 2 + solveRec(nums, i, nums[j]-nums[i]));
                ans = max(ans, 2 + solveMem(dp, nums, i, nums[j]-nums[i]));
            }
        }
        
        return ans;
        */
        
        return solveTab(nums, nums.size());
    }
};