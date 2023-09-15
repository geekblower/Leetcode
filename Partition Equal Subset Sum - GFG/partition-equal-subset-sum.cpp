//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solveMem(vector<vector<int>> &dp, int arr[], int n, int index, int target) {
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(index >= n) return 0;
        if(dp[index][target] != -1) return dp[index][target];
        
        int incl = solveMem(dp, arr, n, index+1, target-arr[index]);
        int excl = solveMem(dp, arr, n, index+1, target);
        
        dp[index][target] = (incl || excl);
        return dp[index][target];
    }
    
    int equalPartition(int N, int arr[]) {
        int sum = 0;
        for(int i=0; i<N; i++) sum += arr[i];
        
        if(sum & 1) return 0;
        
        vector<vector<int>> dp(N+1, vector<int>(sum/2+1, -1));
        return solveMem(dp, arr, N, 0, sum/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends