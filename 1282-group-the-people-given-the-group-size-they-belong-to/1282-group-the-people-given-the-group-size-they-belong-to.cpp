class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> map;
        vector<vector<int>> ans;
        
        for(int i=0; i<groupSizes.size(); i++) {
            map[groupSizes[i]].push_back(i);
        }
        
        for(auto m : map) {
            vector<int> temp = m.second;
            
            if(temp.size() == m.first) {
                ans.push_back(temp);
            } else {
                int n = temp.size() / m.first;
                int index = 0;
                
                for(int i=0; i<n; i++) {
                    int curr = m.first;
                    vector<int> temp2;
                    
                    while(curr--) {
                        temp2.push_back(temp[index++]);    
                    }
                    
                    ans.push_back(temp2);
                }
            }
        }
        
        return ans;
    }
};