class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;
        
        for(int i=0; i<accounts.size(); i++) {
            int customer = 0;
            
            for(int j=0; j<accounts[0].size();j++){
                customer += accounts[i][j];
            }
            
            max_wealth = max(customer,max_wealth);
        }
        
        return max_wealth;
    }
};