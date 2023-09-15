class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int ans = 0;        
        unordered_map<int, int> dp;
        
        for(int i=0; i<n; i++) {
            int temp = arr[i] - difference;
            int tempAns = 0;
            
            if(dp.count(temp)) {
                tempAns = dp[temp];
            }
            
            dp[arr[i]] = 1 + tempAns;
            ans = max(ans, dp[arr[i]]);
        }
        
        return ans;
    }
};