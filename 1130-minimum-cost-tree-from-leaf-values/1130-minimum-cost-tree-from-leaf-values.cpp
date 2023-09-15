class Solution {
public:
    int solveRec(vector<int>& arr, map<pair<int,int>, int>& maxi, int left, int right) {
        if(left == right) return 0;
        
        int ans = INT_MAX;
        
        for(int i=left; i<right; i++) {
            int ansL = solveRec(arr, maxi, left, i);
            int ansR = solveRec(arr, maxi, i+1, right);
            
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + ansL + ansR);
        }
        
        return ans;
    }
    
    int solveMem(vector<vector<int>> &dp, vector<int>& arr, map<pair<int,int>, int>& maxi, int left, int right) {
        if(left == right) return 0;
        
        if(dp[left][right] != -1) {
            return dp[left][right];
        }
        
        int ans = INT_MAX;
        
        for(int i=left; i<right; i++) {
            int ansL = solveMem(dp, arr, maxi, left, i);
            int ansR = solveMem(dp, arr, maxi, i+1, right);
            
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + ansL + ansR);
        }
        
        dp[left][right] = ans;
        return dp[left][right];
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>, int> maxi;
        int n = arr.size();
        
        for(int i=0; i<n; i++) {
            maxi[{i,i}] = arr[i];
            
            for(int j=i+1; j<n; j++) {
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        
        // return solveRec(arr, maxi, 0, n-1);
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solveMem(dp, arr, maxi, 0, n-1);
    }
};