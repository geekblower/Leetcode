class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int a = coordinates[0];
        int b = coordinates[1];
        
        return (a&1) ? ((b&1) ? 0 : 1) : ((b&1) ? 1 : 0);
    }
};