class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L = sqrt(area);
        int W = 1;

        for(int i=2; i<=L; i++) {
            if(area % i == 0) {
                W = i;
            }
        }

        return {area/W, W};
    }
};