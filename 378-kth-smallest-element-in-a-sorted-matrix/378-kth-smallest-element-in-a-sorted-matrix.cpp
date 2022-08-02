class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans[row*col], index=0;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                ans[index] = matrix[i][j];
                index++;
            }
        }
        
        sort(ans, ans+(row*col));
        
        return ans[k-1];
    }
};