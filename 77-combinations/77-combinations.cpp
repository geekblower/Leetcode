class Solution {
public:
    void solve(int i, vector<int> ds, vector<vector<int>> &ans, vector<long long> arr, int k) {
        if(ds.size() == k) {
            ans.push_back (ds);
            return;
        }
        
        for(int j=i; j<arr.size(); j++) {
            ds.push_back (arr[j]);
            solve(j+1, ds, ans, arr, k);
            ds.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<long long> arr;

        for(int i=1;i<=n;i++)
            arr.push_back(i);

        vector<int> ds;
        vector<vector<int>> ans;
        solve(0, ds, ans, arr, k);

        return ans;
    }
};