class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> solution;
        
        for(int i=1; i<=numRows; i++) {
            vector<int> temp;
            temp.push_back (1);
            
            for(int j=2; j<i; j++) {
                int ans = solution[i-2][j-1] + solution[i-2][j-2];
                temp.push_back (ans);
            }
            
            if(i>1)
                temp.push_back (1);
            
            solution.push_back (temp);
        }
        
        return solution;
    }
};