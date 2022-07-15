class Solution {
public:
    int mySqrt(int x) {
        int start = 1;
        int end = x;
        long long int ans = 0;
        
        while(start<=end) {
            long long mid = start + (end-start)/2;
            
            if(mid*mid == x)
                return mid;
            
            if(mid*mid < x) {
                start = mid+1;
                ans = mid;
            } else
                end = mid-1;
        }
        
        return ans;
    }
};