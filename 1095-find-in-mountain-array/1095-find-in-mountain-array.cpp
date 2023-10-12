class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
        
        // Calculating peak index
        int low = 1;
        int high = length-2;
        
        while(low != high) {
            int mid = low + (high - low) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        int peak = low;
        
        // Binary search for the target in the increasing part of the mountain array.
        low = 0;
        high = peak;
        
        while(low != high) {
            int mid = low + (high-low) / 2;

            if (mountainArr.get(mid) < target)
                low = mid + 1;
            else
                high = mid;
        }
        
        if(mountainArr.get(low) == target) 
            return low;
        
        
        // Binary search for the target in the decreasing part of the mountain array.
        low = peak+1;
        high = length-1;
        
        while (low != high) {
            int mid = low + (high - low) / 2;
            
            if (mountainArr.get(mid) > target)
                low = mid + 1;
            else
                high = mid;
        }

        if(mountainArr.get(low) == target) 
            return low;
        
        return -1;
    }
};