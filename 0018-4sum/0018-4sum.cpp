class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> solution;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                int start = j+1;
                int end = nums.size()-1;

                while(start < end) {
                    long long sum = (1ll) * nums[i] + nums[j] + nums[start] + nums[end];

                    if(sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[start], nums[end]};
                        sort(temp.begin(), temp.end());
                        bool flag = true;

                        for(int i=0; i<solution.size(); i++) {
                            if(solution[i] == temp) {
                                flag = false;
                                break;
                            }
                        }

                        if(flag) {
                            solution.push_back(temp);
                        }

                        start++;
                        end--;
                    } else if(sum < target) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }

        return solution;
    }
};