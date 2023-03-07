class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>> &solution, vector<int> output, int index) {
        if(index == nums.size()) {
            bool flag = true;
            for(int i=0; i<solution.size(); i++) {
                if(solution[i] == output) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                solution.push_back (output);
            }
            return;
        }
        
        solve(nums, solution, output, index+1);
        
        output.push_back (nums[index]);
        solve(nums, solution, output, index+1);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> solution;
        vector<int> output;
        int index = 0;
        
        solve(nums, solution, output, index);
        sort(solution.begin(), solution.end());
        
        return solution;
    }
};