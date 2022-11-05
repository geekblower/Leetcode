class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> answer;
        
        int i=0, j=0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        while(i<len1 && j<len2) {
            //cout<<"In loop for i = "<<i<<" & j = "<<j<<" & len1 = "<<len1<<" & len2 = "<<len2<<endl;
            if(nums1[i]<nums2[j]) {
                //cout<<"One\n";
                i++;
            } else if(nums1[i]>nums2[j]) {
                //cout<<"Two\n";
                j++;
            } else {
                //cout<<"Third\n";
                answer.push_back (nums1[i]);
                i++;
                j++;
            }
        }
        
        return answer;
    }
};