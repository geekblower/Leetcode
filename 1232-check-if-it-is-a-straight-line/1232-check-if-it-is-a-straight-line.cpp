class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float diff = (float)(coordinates[1][0] - coordinates[0][0]) / (coordinates[1][1] - coordinates[0][1]);

        if(coordinates[1][1] == coordinates[0][1])
            diff = -100000;

        for(int i{2}; i<coordinates.size(); ++i) {
            if(coordinates[i][1]==coordinates[i-1][1]) {
                if(diff==-100000)
                    continue;
                else
                    return false;
            }

            if(((float)(coordinates[i][0] - coordinates[i-1][0]) / (coordinates[i][1] - coordinates[i-1][1]))==diff)
                continue;
            else
                return false;
        }
        
        return true;
    }
};