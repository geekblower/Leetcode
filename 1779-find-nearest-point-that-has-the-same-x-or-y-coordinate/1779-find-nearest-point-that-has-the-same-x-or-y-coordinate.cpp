class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int manhattan = INT_MAX;
        
        for(int i=0; i<points.size(); i++) {
            if(points[i][0]==x || points[i][1]==y) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int temp = abs(x-x1) + abs(y-y1);
                
                if(temp < manhattan) {
                    manhattan = temp;
                    ans = i;
                }
            }
        }
        
        return ans;
    }
};