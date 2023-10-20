class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> solution;
        
        for(int i=0; i<nums.size(); i++) {
            int x = nums[i];
            string curr;
            bool flag = false;
            
            curr += to_string(x);
            
            while(i < nums.size()-1 && nums[i+1] == x+1) {
                i++;
                x++;
                flag = true;
            }
            
            if(flag) curr = curr + "->" + to_string(x);
            solution.push_back(curr);
        }
        
        return solution;
    }
};