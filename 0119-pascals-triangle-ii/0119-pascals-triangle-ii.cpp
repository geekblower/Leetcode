class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        
        vector<int> sol(2,1);
        
        for(int i=2; i<=rowIndex; i++) {
            vector<int> temp(i+1, 1);

            for(int j=0, c=1; j<sol.size()-1; j++) {
                temp[c++] = sol[j] + sol[j+1];
            }

            sol = temp;
        }
        
        return sol;
    }
};