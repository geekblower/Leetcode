class Solution {
public:
    int solveRec(vector<int>& nums1, vector<int>& nums2, int index, bool swapped) {
        // Base case
        if(index == nums1.size()) return 0;
        
        int ans = INT_MAX;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        
        // Catch
        if(swapped) swap(prev1, prev2);
        
        // No swap case
        if(nums1[index] > prev1 && nums2[index] > prev2) {
            ans = solveRec(nums1, nums2, index+1, false);
        }
        
        // Swap case
        if(nums1[index] > prev2 && nums2[index] > prev1) {
            ans = min(ans, 1 + solveRec(nums1, nums2, index+1, true));
        }
        
        return ans;
    }
    
    int solveMem(vector<vector<int>> &dp, vector<int>& nums1, vector<int>& nums2, int index, bool swapped) {
        // Base case
        if(index == nums1.size()) return 0;
        
        if(dp[index][swapped] != -1) return dp[index][swapped];
        
        int ans = INT_MAX;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        
        // Catch
        if(swapped) swap(prev1, prev2);
        
        // No swap case
        if(nums1[index] > prev1 && nums2[index] > prev2) {
            ans = solveMem(dp, nums1, nums2, index+1, false);
        }
        
        // Swap case
        if(nums1[index] > prev2 && nums2[index] > prev1) {
            ans = min(ans, 1 + solveMem(dp, nums1, nums2, index+1, true));
        }
        
        dp[index][swapped] = ans;
        return dp[index][swapped];
    }

    int solveTab(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int index=n-1; index>=1; index--) {
            for(int swapped=1; swapped>=0; swapped--) {
                int ans = INT_MAX;
        
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // Catch
                if(swapped) swap(prev1, prev2);

                // No swap case
                if(nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = dp[index+1][0];
                }

                // Swap case
                if(nums1[index] > prev2 && nums2[index] > prev1) {
                    ans = min(ans, 1 + dp[index+1][1]);
                }

                dp[index][swapped] = ans;
            }
        }
        
        return dp[1][0];
    }
    
    int solveSpc(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        
        for(int index=n-1; index>=1; index--) {
            for(int swapped=1; swapped>=0; swapped--) {
                int ans = INT_MAX;
        
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // Catch
                if(swapped) swap(prev1, prev2);

                // No swap case
                if(nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = next[0];
                }

                // Swap case
                if(nums1[index] > prev2 && nums2[index] > prev1) {
                    ans = min(ans, 1 + next[1]);
                }

                curr[swapped] = ans;
            }
            next = curr;
        }
        
        return next[0];
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        bool swapped = false;
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        // return solveRec(nums1, nums2, 1, swapped);
        
        // vector<vector<int>> dp(nums1.size()+1, vector<int>(2, -1));
        // return solveMem(dp, nums1, nums2, 1, swapped);
        
        // return solveTab(nums1, nums2);
        
        return solveSpc(nums1, nums2);
    }
};