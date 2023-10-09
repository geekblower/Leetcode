class Solution {
public:
    int firstPosition(vector<int> arr, int key) {
        int start = 0;
        int end = arr.size()-1;
        int mid = start + (end-start)/2;

        int ans = -1;

        while(start <= end) {
            if(arr[mid] == key) {
                ans = mid;
                end = mid - 1;
            } else if(key > arr[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }

            mid = start + (end-start)/2;
        }

        return ans;
    }

    int lastPosition(vector<int> arr, int key) {
        int start = 0;
        int end = arr.size()-1;
        int mid = start + (end-start)/2;

        int ans = -1;

        while(start <= end) {
            if(arr[mid] == key) {
                ans = mid;
                start = mid + 1;
            } else if(key > arr[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }

            mid = start + (end-start)/2;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> solution;

        solution.push_back (firstPosition(nums, target));
        solution.push_back (lastPosition(nums, target));

        return solution;
    }
};
