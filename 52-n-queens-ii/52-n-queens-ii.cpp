class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n), diag(2*n-1), anti_diag(2*n-1);
        return solve(col, diag, anti_diag, 0);
    }
    
    int solve(vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int row) {
        int n = size(col), count = 0;
        
        if(row == n)
            return 1;
        
        for(int c=0; c<n; c++) {         
            if(!col[c] && !diag[row+c] && !anti_diag[row-c+n-1]) {
                col[c] = diag[row+c] = anti_diag[row-c+n-1] = true;
                count += solve(col, diag, anti_diag, row+1); 
                col[c] = diag[row+c] = anti_diag[row-c+n-1] = false; 
            }
        }
        
        return count;
    }
};