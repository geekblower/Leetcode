class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int start = 0;
        int end = numbers.size()-1;
        
        while(start <= end) {
            if(numbers[start] + numbers[end] == target) {
                ans.push_back (start+1);
                ans.push_back (end+1);
                return ans;
            }
            
            if(numbers[start] + numbers[end] > target)
                end--;
            else
                start++;
        }
        
        return ans;
    }
};