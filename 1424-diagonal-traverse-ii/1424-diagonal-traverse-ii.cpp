class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int size = nums.size();
        unordered_map<int, vector<int>> map;
        
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums[i].size(); j++) {
                map[i+j].push_back(nums[i][j]);
            }
        }
        
        vector<int> solution;
        
        for(int i=0; i<map.size(); i++) {
            reverse(map[i].begin(), map[i].end());
            
            for(int l : map[i]) {
                solution.push_back(l);
            }
        }
        
        return solution;
    }
};