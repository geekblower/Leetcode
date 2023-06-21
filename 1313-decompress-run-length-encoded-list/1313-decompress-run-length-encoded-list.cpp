class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> solution;
        
        for(int i=0; i<nums.size()-1; i+=2) {
            int value = nums[i+1];
            
            for(int j=0; j<nums[i]; j++) {
                solution.push_back (value);
            }
        }
        
        return solution;
    }
};