// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int ans = 0;
    int possible_paths(vector<vector<int>>edges, int n, int s, int d) {
        if(n==1)
            return 1;
        
        vector<vector<int>> adj;
        for(int i=0; i<n; i++)
            adj.push_back({});
        
        for(int i=0; i<edges.size(); i++)
            adj[edges[i][0]].push_back(edges[i][1]);
        
        vector<int> visited(n,0);
        DFS(s, adj, visited, d, n);
        
        return ans;
    }
    
    void DFS(int index, vector<vector<int>> &adj, vector<int> &visited, int d, int n) {
        visited[index] = 1;
        
        if(index==d) {
            ans++;
            visited[d] = 0;
            return;
        }
        
        for(int i = 0; i<adj[index].size(); i++) {
            if(!visited[adj[index][i]]) {
                DFS(adj[index][i], adj, visited, d, n);
            }
        }
        
        visited[index]=0;
    }

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends