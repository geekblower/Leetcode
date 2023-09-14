class Solution {
public:
    bool solveRec(vector<int>& nums, int index, int target) {
        if(target == 0) return true;
        if(target < 0) return false;
        if(index >= nums.size()) return false;
        
        bool incl = solveRec(nums, index+1, target-nums[index]);
        bool excl = solveRec(nums, index+1, target);
        
        return (incl || excl);
    }
    
    bool solveMem(vector<vector<int>> &dp, vector<int>& nums, int index, int target) {
        if(target == 0) return true;
        if(target < 0) return false;
        if(index >= nums.size()) return false;
        
        if(dp[index][target] != -1) {
            return dp[index][target];
        }
        
        bool incl = solveMem(dp, nums, index+1, target-nums[index]);
        bool excl = solveMem(dp, nums, index+1, target);
        
        dp[index][target] = (incl || excl);
        return dp[index][target];
    }
    
    bool solveTab(vector<int>& nums, int n, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        for(int i=0; i<=n; i++) {
            dp[i][0] = true;
        }
        
        for(int i=n-1; i>=0; i--) {
            for(int t=0; t<=target; t++) {
                
                bool incl = false;
                if(t - nums[i] >= 0)
                    incl = dp[i+1][t-nums[i]];
                
                bool excl = dp[i+1][t];

                dp[i][t] = (incl || excl);
                
            }
        }
        
        return dp[0][target];
    }
    
    bool solveSpc(vector<int>& nums, int n, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);
        
        curr[0] = next[0] = true;
        
        for(int i=n-1; i>=0; i--) {
            for(int t=0; t<=target; t++) {
                
                bool incl = false;
                if(t - nums[i] >= 0)
                    incl = next[t-nums[i]];
                
                bool excl = next[t];

                curr[t] = (incl || excl);
                
            }
            next = curr;
        }
        
        return next[target];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) sum += nums[i];
        int target = sum/2;
        
        // Making two subsets is not possible as total sum is odd
        if(sum & 1) return false;
        
        // return solveRec(nums, 0, target);
        
        // vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        // return solveMem(dp, nums, 0, target);
        
        // return solveTab(nums, nums.size(), target);
        
        return solveSpc(nums, nums.size(), target);
    }
};