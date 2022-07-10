// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    void solve(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int>& temp, vector<vector<int>> &result) {
        if(x==n-1 && y==m-1) {
            temp.push_back (grid[x][y]);
            result.push_back (temp);
            temp.pop_back ();
            return;
        }
        
        temp.push_back (grid[x][y]);
        if(x+1<n)
            solve(x + 1 , y , n , m , grid , vis , temp , result);
        
        if(y+1<m)
            solve(x, y+1, n, m, grid, vis, temp, result);
        
        temp.pop_back();
    }
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<vector<int>>vis(n, vector<int> (m,0));
        
        solve(0, 0, n, m, grid, vis, temp, result);
        return result;
    }

};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends