class Solution {
    public:
        vector<int> adj[1000];
    
        static bool compare(string &a,string &b) {
            return a.size()<b.size();
        }

        bool f(string &a, string &b) {
            if(a.size()+1!=b.size())
                return false;
            
            int diff=0, i=0, j=0;
            
            while(i<a.size() and j<b.size()) {
                if(a[i]==b[j])
                    i++, j++;
                else if(diff==0)
                    diff++, j++;
                else
                    return false;
            }
            
            return true;
        }

        void dfs(int node, vector<int>& vis, vector<int> &dp) {
            vis[node] = 1;
            dp[node] = 1;
            
            for(auto it:adj[node]) {
                if(!vis[it]) dfs(it, vis, dp);
                dp[node] = max(dp[node], 1+dp[it]);
            }
        }

        int longestStrChain(vector<string>& words) {
            int n = words.size(), ans=1;
            sort(words.begin(), words.end(), compare);
            for(int i=0; i<n; i++)
                for(int j=i+1; j<n && words[i].size()+1>=words[j].size(); j++)
                    if(f(words[i], words[j]))
                        adj[i].push_back(j);

            vector<int> vis(n,0), dp(n,-1);
            
            for(int i=0; i<n; i++)
                if(!vis[i])
                    dfs(i, vis, dp);
            
            for(int i=0; i<n; i++)
                ans = max(ans, dp[i]);
            
            return ans;
        }
};