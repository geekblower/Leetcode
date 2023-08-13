class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()-k];

        // Another way without sorting - Using max heap
        priority_queue<int> maxHeap;
        for(int i=0; i<nums.size(); i++) {
            maxHeap.push(nums[i]);
        }

        for(int i=1; i<k; i++) {
            maxHeap.pop();
        }

        return maxHeap.top();
    }
};