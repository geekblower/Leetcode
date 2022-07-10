class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), count=0;
        vector<long> sum;
        long n1 = 0;
        for(int i=0; i<n; i++) {
            n1 += nums[i];
            sum.push_back(n1);
        }
        
        for(int i=0; i<n-1; i++) {
            if(sum[i] >= (sum[n-1] - sum[i]))
                count++;
        }
        
        return count;
    }
};