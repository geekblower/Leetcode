class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solution;
        sort(nums.begin(), nums.end());
        
        if(nums[0]>0 || nums[nums.size()-1]<0) {
            return solution;
        }

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0) {
                return solution;
            }

            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }

            int start = i+1;
            int end = nums.size()-1;

            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];

                if(sum == 0) {
                    solution.push_back({nums[i], nums[start], nums[end]});
                    
                    start++;
                    end--;

                    while(start<end && nums[start]==nums[start-1]) {
                        start++;
                    }

                    while(start<end && nums[end]==nums[end+1]) {
                        end--;
                    }

                } else if(sum < 0) {
                    start++;
                } else {
                    end--;
                }

            }
        }
        
        return solution;
    }
};