class Solution {
public:
    void dfs(unordered_map<int, list<int>> &adj, vector<bool> &visited, int i, pair<int,int> &ans) {
        visited[i] = true;
        ans.second++;
        
        for(int x : adj[i]) {
                ans.first++;

            if(!visited[x]) {
                dfs(adj, visited, x, ans);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n,0);
        int count = 0;
        
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                pair<int, int> ans({0,0});

                dfs(adj, visited, i, ans);
                
                int nodeCount = ans.second;
                int edgeCount = ans.first/2;
                
                if((nodeCount*(nodeCount-1))/2 == edgeCount) {
                    count++;
                }
            }
        }
        
        return count;
    }
};