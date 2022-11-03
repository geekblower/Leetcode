class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++) {
            int contribution = ceil((i+1)*(n-i)/2.0);
            ans += (contribution*arr[i]);
        }
        
        return ans;
    }
};