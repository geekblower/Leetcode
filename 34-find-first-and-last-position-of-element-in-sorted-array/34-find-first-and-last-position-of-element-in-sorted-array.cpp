class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> solution;
        int s = 0, e = nums.size() - 1;
        int m = s + (e-s)/2;
        int ans = -1;

        while(s<=e) {
            if(nums[m] == target) {
                ans = m;
                e = m - 1;
            }

            if(nums[m] > target) {
                e = m - 1;
            }

            if(nums[m] < target) {
                s = m + 1;
            }

            m = s + (e-s)/2;
        }
        
        solution.push_back (ans);
        
        s = 0, e = nums.size() - 1;
        m = s + (e-s)/2;
        ans = -1;

        while(s<=e) {
            if(nums[m] == target) {
                ans = m;
                s = m + 1;
            }

            if(nums[m] > target) {
                e = m - 1;
            }

            if(nums[m] < target) {
                s = m + 1;
            }

            m = s + (e-s)/2;
        }
        
        solution.push_back (ans);

    return solution;
    }
};