class Solution {
public:
/*
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;
        int size = matrix.size();
        
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                matrix[i][j] = temp[size-j-1][i];
            }
        }
    }
*/
    // Optimised solution without using extra space
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n-i; j++) {
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }
    }
};