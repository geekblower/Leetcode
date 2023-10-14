class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int underscore = 0;
        int left = 0;
        int right = 0;
        
        for(int i=0; i<moves.length(); i++) {
            switch(moves[i]) {
                case 'L': left++; break;
                case 'R': right++; break;
                case '_': underscore++; break;
            }
        }
        
        return (left>right) ? (left+underscore) - right : (right+underscore) - left;
    }
};