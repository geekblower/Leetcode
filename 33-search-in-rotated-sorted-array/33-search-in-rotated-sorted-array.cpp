class Solution {
public:
    int FindPivot(vector<int> arr, int size) {
        int start=0;
        int end=size-1;
    
        while(start < end) {
            int mid = start + (end-start)/2;
            
            if(arr[mid] >= arr[0])
                start = mid + 1;
            else
                end = mid;
        }

        return start;
    }

    int BinarySearch(vector<int> arr, int start, int end, int k) {
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(arr[mid] == k)
                return mid;
        
            if(arr[mid] < k)
                start = mid + 1;
            else
            end = mid - 1;
        }

        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        int p = FindPivot(nums, nums.size());
        
        if((target <= nums[nums.size()-1]) && (target >= nums[p]))
            return BinarySearch(nums, p, nums.size()-1, target);
        else
            return BinarySearch(nums, 0, p-1, target);
    }
};