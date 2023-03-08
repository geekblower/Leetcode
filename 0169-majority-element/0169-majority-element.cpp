class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxOcc = 0;
        int answer = -1;
        
        for(int i=0; i<nums.size(); ) {
            int temp = nums[i];
            int count = 0;
            
            while(i<nums.size() && nums[i]==temp) {
                i++;
                count++;
            }
            
            if(count > maxOcc) {
                maxOcc = count;
                answer = temp;
            }
        }
        
        return answer;
    }
};