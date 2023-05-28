class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        int total = row * col;

        int frow = 0;               // First Row
        int fcol = 0;               // First Coloumn
        int lrow = row-1;           // Last Row
        int lcol = col-1;           // Last Column

        while(count < total) {
            for(int i=fcol; count<total && i<=lcol; i++) {
                ans.push_back (matrix[frow][i]);
                count++;
            }
            frow++;

            for(int i=frow; count<total && i<=lrow; i++) {
                ans.push_back (matrix[i][lcol]);
                count++;
            }
            lcol--;

            for(int i=lcol; count<total && i>=fcol; i--) {
                ans.push_back (matrix[lrow][i]);
                count++;
            }
            lrow--;

            for(int i=lrow; count<total && i>=frow; i--) {
                ans.push_back (matrix[i][fcol]);
                count++;
            }
            fcol++;
        }
        
        return ans;
    }
};