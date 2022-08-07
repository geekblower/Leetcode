class Solution {
public:
    // MERGE SORTING
    void mergeArrays(vector<int>& nums, int start, int end) {
        int mid = start + (end-start)/2;
        int index = start;
        
        int len1 = mid-start+1;
        int len2 = end-mid;
        
        int *firstArray = new int[len1];
        int *secondArray = new int[len2];
        
        for(int i=0; i<len1; i++) {
            firstArray[i] = nums[index++];
        }
        
        index = mid+1;
        for(int i=0; i<len2; i++) {
            secondArray[i] = nums[index++];
        }
        
        int i=0, j=0;
        index = start;
        
        while(i<len1 && j<len2) {
            if(firstArray[i] < secondArray[j])
                nums[index++] = firstArray[i++];
            else if(firstArray[i] > secondArray[j])
                nums[index++] = secondArray[j++];
            else {
                nums[index++] = firstArray[i++];
                nums[index++] = secondArray[j++];
            }
        }
        
        while(i < len1)
                nums[index++] = firstArray[i++];
        
        while(j < len2)
                nums[index++] = secondArray[j++];
    }
    
    void mergeSort(vector<int>& nums, int start, int end) {
        if(start >= end)
            return;
        
        int mid = start + (end-start)/2;
        
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        
        mergeArrays(nums, start, end);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};