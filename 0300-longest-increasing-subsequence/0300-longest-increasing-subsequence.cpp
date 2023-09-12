class Solution {
public:
    int solveRec(vector<int> &nums, int curr, int prev) {
        // Base case
        if(curr == nums.size()) {
            return 0;
        }
        
        // Include
        int incl = 0;
        if(prev == -1 || nums[curr] > nums[prev]) {
            incl = 1 + solveRec(nums, curr+1, curr);
        }
        
        // Exclude
        int excl = solveRec(nums, curr+1, prev);
        
        return max(incl, excl);
    }
    
    int solveMem(vector<vector<int>> &dp, vector<int> &nums, int curr, int prev) {
        // Base case
        if(curr == nums.size()) {
            return 0;
        }
        
        if(dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }
        
        // Include
        int incl = 0;
        if(prev == -1 || nums[curr] > nums[prev]) {
            incl = 1 + solveMem(dp, nums, curr+1, curr);
        }
        
        // Exclude
        int excl = solveMem(dp, nums, curr+1, prev);
        
        dp[curr][prev+1] = max(incl, excl);
        return dp[curr][prev+1];
    }
    
    int solveTab(vector<int> &nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));
        
        for(int curr=nums.size()-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {
                // Include
                int incl = 0;
                if(prev == -1 || nums[curr] > nums[prev]) {
                    incl = 1 + dp[curr+1][curr+1];
                }

                // Exclude
                int excl = dp[curr+1][prev+1];

                dp[curr][prev+1] = max(incl, excl);
            }
        }
            
        return dp[0][0];
    }
    
    int solveSpc(vector<int> &nums) {
        vector<int> currRow(nums.size()+1, 0);
        vector<int> nextRow(nums.size()+1, 0);
        
        for(int curr=nums.size()-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {
                // Include
                int incl = 0;
                if(prev == -1 || nums[curr] > nums[prev]) {
                    incl = 1 + nextRow[curr+1];
                }

                // Exclude
                int excl = nextRow[prev+1];

                currRow[prev+1] = max(incl, excl);
            }
            
            nextRow = currRow;
        }
            
        return nextRow[0];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // return solveRec(nums, 0, -1);    
        
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        // return solveMem(dp, nums, 0, -1);
        
        // return solveTab(nums);
        
        return solveSpc(nums);
    }
};