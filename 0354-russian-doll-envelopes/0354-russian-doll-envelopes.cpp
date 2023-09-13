class Solution {
public:
    int solveBinarySearch(vector<vector<int>>& env, int n) {
        if(n == 0) {
            return 0;
        }
        
        vector<int> ans;
        ans.push_back(env[0][1]);
        
        for(int i=1; i<n; i++) {
            if(env[i][1] > ans.back()) {
                ans.push_back(env[i][1]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), env[i][1]) - ans.begin();
                ans[index] = env[i][1];
            }
        }
        
        return ans.size();
    }
    
    static bool compare(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        return solveBinarySearch(envelopes, envelopes.size());
    }
};