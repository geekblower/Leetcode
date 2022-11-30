class Solution {
public:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& solution) {
        if(index >= nums.size()) {
            solution.push_back (output);
            return;
        }
        
        solve(nums, output, index+1, solution);
        
        output.push_back (nums[index]);
        solve(nums, output, index+1, solution);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> solution;
        int index = 0;
        
        solve(nums, output, index, solution);
        
        return solution;
    }
};