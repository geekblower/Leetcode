class Solution {
public:
    bool outBounds (const int i, const int j, const int m, const int n) {
        return !((i >= 0 && i < m) && (j >= 0 && j < n));
    }

    void dfs (vector<vector<int>>& grid, const int i, const int j, int &counter) {
        int m = grid.size();
        int n = grid[0].size();

        if(!outBounds(i, j, m, n)) {
            if(grid[i][j] == 1) {
                counter++;
                grid[i][j] = 0;
                dfs(grid, i-1, j, counter);
                dfs(grid, i, j+1, counter);
                dfs(grid, i+1, j, counter);
                dfs(grid, i, j-1, counter);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    int counter = 0;
                    dfs(grid, i, j, counter);
                    if(counter > ans)
                        ans = counter;
                }
            }
        }

        return ans;
    }
};