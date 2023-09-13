class Solution {
public:
    bool check(vector<int> base, vector<int> newBox) {
        return (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]);
    }
    
    int solve(vector<vector<int>> &cub, int n) {
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {
                
                int incl = 0;
                if(prev == -1 || check(cub[curr], cub[prev])) {
                    incl = cub[curr][2] + nextRow[curr+1];
                }
                
                int excl = nextRow[prev+1];
                
                currRow[prev+1] = max(incl, excl);
            }
            
            nextRow = currRow;
        }
        
        return nextRow[0];
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1 : Sort dimensions of all cuboids
        for(auto &c : cuboids) {
            sort(c.begin(), c.end());
        }
        
        // Step 2 : Sort all cuboids
        sort(cuboids.begin(), cuboids.end());
        
        // Step 3 : Use LIS
        return solve(cuboids, cuboids.size());
    }
};