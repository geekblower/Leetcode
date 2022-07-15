// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n) {
        sort(arr, arr+n);
        long long int num1=0, num2=0;
        bool flag = true;
        
        for(int i=0; i<n; i++) {
            if(flag) {
                num1 = (num1 * 10) + arr[i];
                flag = false;
            } else {
                num2 = (num2 * 10) + arr[i];
                flag = true;
            }
        }
        
        return num1+num2;

    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends