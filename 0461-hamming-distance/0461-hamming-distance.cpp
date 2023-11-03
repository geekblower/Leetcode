class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int dis = 0;
        
        while(x!=0 || y!=0) {
            
            if((x&1) != (y&1)) dis++;
            
            x = x >> 1;
            y = y >> 1;
            
        }
        
        return dis;
        
    }
};