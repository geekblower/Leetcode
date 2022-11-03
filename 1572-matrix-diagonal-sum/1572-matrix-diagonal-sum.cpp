class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int start = 0;
        int end = mat[0].size()-1;
        
        for(int i=0; i<mat.size()/2; i++) {
            ans += (mat[i][start]+mat[i][end]);
            ans += mat[mat[0].size()-1-i][start]+ mat[mat[0].size()-1-i][end];
            
            start++;
            end--;
        }
        
        if(mat.size()&1) {
            ans += mat[mat.size()/2][mat.size()/2];
        }
        
        return ans;
    }
};