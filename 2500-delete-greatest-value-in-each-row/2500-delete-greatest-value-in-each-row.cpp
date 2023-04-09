class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++) {
            sort(grid[i].begin(), grid[i].end());
        }

        int size = grid[0].size();
        int ans = 0;

        for(int i=0; i<size; i++) {
            int maxValue = INT_MIN;
            for(int j=0; j<grid.size(); j++) {
                maxValue = max(grid[j][i], maxValue);
            }

            ans += maxValue;
        }

        return ans;
    }
};