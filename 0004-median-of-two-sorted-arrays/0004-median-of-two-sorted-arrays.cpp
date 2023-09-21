class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;        
        int n = nums1.size();
        int m = nums2.size();
        
        int i=0, j=0;
        
        while(i<n && j<m) {
            if(nums1[i] < nums2[j]) temp.push_back(nums1[i++]);
            else temp.push_back(nums2[j++]);
        }
        
        while(i<n) temp.push_back(nums1[i++]);
        while(j<m) temp.push_back(nums2[j++]);
        
        int len = temp.size();
        
        if(len & 1) return (double) temp[len/2];
        else return (double) (temp[len/2] + temp[len/2-1]) / 2;
    }
};