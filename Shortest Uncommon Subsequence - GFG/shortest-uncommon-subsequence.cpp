// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int shortestUnSub(string S, string T) {
        int n=S.length(), m=T.length();
        int dp[n+1][m+1];
        int MAX = 600;
        
        for(int i=0; i<=n; i++)
            dp[i][0]=1;
            
        for(int i=0; i<=m; i++)
            dp[0][i]=MAX;
            
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                int k;
                
            for(k=j-1; k>=0; k--) {
                if(T[k]==S[i-1])
                    break;
            }
                    
            if(k<0)
                dp[i][j]=1;
            else
                dp[i][j] = min(dp[i-1][j], dp[i-1][k]+1);
            }
        }
            
        if(dp[n][m]>=MAX)
            return -1;
            
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends