class Solution {
public:
    void dfsCount(unordered_map<int, list<int>> &adj, vector<bool> &visited, int i, pair<int,int> &ans) {
        visited[i] = true;
        ans.second++;
        
        for(int x : adj[i]) {
                ans.first++;
            if(!visited[x]) {
                // count++;
                dfsCount(adj, visited, x, ans);
            }
        }
    }

    bool dfs(unordered_map<int, list<int>> &adj, vector<bool> &visited, int i, int len) {
        visited[i] = true;
        
        for(int x : adj[i]) {
            if(adj[x].size() != len) return false;
            
            if(!visited[x]) {
                bool ans = dfs(adj, visited, x, len);
                if(ans == false) return false;
            }
        }
        
        return true;
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
                int cnt = 0;
                pair<int, int> ans({0,0});
                // vector<bool> temp = visited;
                dfsCount(adj, visited, i, ans);
                // cout << "cnt : " << cnt << endl;
                
                // if(dfs(adj, visited, i, cnt+1)) count++;
                
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