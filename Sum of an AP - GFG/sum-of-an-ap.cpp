//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
		int sum_of_ap(int n,int a, int d)
		{
		    int sum = 0;
		    
		    for(int i=0; i<n; i++) {
		        sum += a;
		        a += d;
		    }
		    
		    return sum;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n, a, d;
    	cin >> n >> a >> d;
    	Solution ob;
    	int ans = ob.sum_of_ap(n, a, d);
    	cout << ans << "\n";
    }
	return 0;
}
// } Driver Code Ends