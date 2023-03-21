class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        for(int i=0; i<grid.size(); i++) {
            if(grid[i][0] < 0) {
                count += (grid[i].size() * (grid.size() - i));
                break;
            }

            int start = 0;
            int end = grid[i].size() - 1;
            int index = grid[i].size();

            while(start <= end) {
                int mid = start + (end-start)/2;

                if(grid[i][mid] < 0) {
                    index = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            count += (grid[i].size() - index);
        }

        return count;
    }
};