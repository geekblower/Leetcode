class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> solution;
        sort(nums1.begin(), nums1.end());
        
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                
                if(nums1[i] == nums2[j]) {
                    solution.push_back (nums1[i]);
                    
                    while(i < nums1.size()-1 && nums1[i+1] == nums2[j]) {
                        i++;
                    }
                    
                    nums2[j] = -1;
                    break;
                }
            
            }
        }
        
        return solution;
    }
};