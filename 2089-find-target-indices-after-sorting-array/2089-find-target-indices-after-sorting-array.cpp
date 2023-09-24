class Solution {
public:
    int firstIndex(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target) {
                ans = mid;
                end = mid - 1;
            } else if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return ans;
    }
    
    int lastIndex(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target) {
                ans = mid;
                start = mid + 1;
            } else if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return ans;
    }
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int first = firstIndex(nums, target);
        int last = lastIndex(nums, target);
        
        vector<int> solution;
        for(int i=first; i<=last && first != -1 && last != -1; i++) solution.push_back(i);
        if(first!=-1 && last==-1) solution.push_back(first);
        
        return solution;
    }
};