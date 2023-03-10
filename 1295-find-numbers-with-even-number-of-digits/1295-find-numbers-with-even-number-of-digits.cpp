class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int answer = 0;
        
        for(int i=0; i<nums.size(); i++) {
            int temp = nums[i];
            int digits = 0;
            
            while(temp) {
                digits++;
                temp /= 10;
            }
            
            if(digits%2 == 0) {
                answer++;
            }
        }
        
        return answer;
    }
};