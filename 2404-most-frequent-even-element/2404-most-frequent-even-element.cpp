class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int answer = -1;
        int maxCount = 0;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] & 1) {
                continue;
            }

            int temp = nums[i];
            int count = 0;

            while(i<nums.size() && nums[i]==temp) {
                i++;
                count++;
            }

            if(count > maxCount) {
                answer = temp;
                maxCount = count;
            }

            i--;
        }

        return answer;
    }
};