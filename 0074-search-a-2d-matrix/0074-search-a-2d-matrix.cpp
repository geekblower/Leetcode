class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = (row*col) - 1;

        while(start <= end) {
            int mid = start + (end-start)/2;
            int i = mid / col;
            int j = mid % col;

            if(matrix[i][j] == target) {
                return true;
            }

            if(matrix[i][j] > target) {
                end = mid - 1;
            }

            if(matrix[i][j] < target) {
                start = mid + 1;
            }
        }

        return false;
    }
};