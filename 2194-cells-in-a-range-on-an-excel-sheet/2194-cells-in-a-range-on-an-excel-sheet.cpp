class Solution {
public:
    vector<string> cellsInRange(string s) {
        int x1 = s[0] - 'A';
        int y1 = s[1] - '0';
        int x4 = s[3] - 'A';
        int y4 = s[4] - '0';
        
        vector<string> res;
		string cell = "XX";
        
        for(int x=x1; x<=x4; x++) {
            for(int y=y1; y<=y4; y++) {
                cell[0] = 'A' + x;
                cell[1] = '0' + y;
                
                res.push_back (cell);
            }
        }
        
        return res;
    }
};