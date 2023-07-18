class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> solution;

        for(int i=0; i<n; i++) {
            solution.push_back (nums[i]);
            solution.push_back (nums[i+n]);
        }

        return solution;
    }
};

