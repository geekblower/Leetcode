//{ Driver Code Starts
// Driver function
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string reciprocalString(string S)
    {
        string ans;
        
        for(int i=0; i<S.length(); i++) {
            char ch = S[i];
            if(S[i]>='A' && S[i]<='Z') {
                int x = 90 - (ch - 'A');
                ch = char(x);
            }
            
            if(S[i]>='a' && S[i]<='z') {
                int x = 122 - (ch - 'a');
                ch = char(x);
            }
            
            ans.push_back(ch);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    string S;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        getline(cin,S);
        Solution ob;
        string reciprocal = ob.reciprocalString(S);
        cout<< reciprocal <<endl;

    }

	return 0;
}
// } Driver Code Ends