class Solution {
public:
    int solveRec(vector<vector<char>>& matrix, int i, int j, int &maxi) {
        if(i >= matrix.size() || j >= matrix[0].size()) {
            return 0;
        }
        
        int right = solveRec(matrix, i, j+1, maxi);
        int diagonal = solveRec(matrix, i+1, j+1, maxi);
        int bottom = solveRec(matrix, i+1, j, maxi);
        
        if(matrix[i][j] == '1') {
            int ans = 1 + min(right, min(bottom, diagonal));
            maxi = max(maxi, ans);
            return ans;
        } else {
            return 0;
        }
    }
    
    int solveMem(vector<vector<int>>& dp, vector<vector<char>>& matrix, int i, int j, int &maxi) {
        if(i >= matrix.size() || j >= matrix[0].size()) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int right = solveMem(dp, matrix, i, j+1, maxi);
        int diagonal = solveMem(dp, matrix, i+1, j+1, maxi);
        int bottom = solveMem(dp, matrix, i+1, j, maxi);
        
        if(matrix[i][j] == '1') {
            dp[i][j] = 1 + min(right, min(bottom, diagonal));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        } else {
            dp[i][j] = 0;
            return dp[i][j];
        }
    }
    
    int solveTab(vector<vector<char>>& matrix, int row, int col, int &maxi) {
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        
        for(int i=row-1; i>=0; i--) {
            for(int j=col-1; j>=0; j--) {
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int bottom = dp[i+1][j];

                if(matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(right, min(bottom, diagonal));
                    maxi = max(maxi, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }        
            }
        }
        
        return maxi;
    }
    
    int solveSpc(vector<vector<char>>& matrix, int row, int col, int &maxi) {
        vector<int> curr(col+1, 0);
        vector<int> next(col+1, 0);

        for(int i=row-1; i>=0; i--) {
            for(int j=col-1; j>=0; j--) {
                int right = curr[j+1];
                int diagonal = next[j+1];
                int bottom = next[j];

                if(matrix[i][j] == '1') {
                    curr[j] = 1 + min(right, min(diagonal, bottom));
                    maxi = max(maxi, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }

            next = curr;
        }
        
        return maxi;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        
        // solveRec(matrix, 0, 0, maxi);
        
        // vector<vector<int>> dp(row, vector<int>(col, -1));
        // solveMem(dp, matrix, 0, 0, maxi);
        
        // solveTab(matrix, row, col, maxi);
        
        solveSpc(matrix, row, col, maxi);
        return maxi*maxi;
    }
};