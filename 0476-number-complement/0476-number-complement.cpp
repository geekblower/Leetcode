class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        long long count = 1;
        
        while(num != 0) {
            int bit = ((num&1) ^ 1);
            if(bit) ans += count;
            num = num >> 1;
            count *= 2;
        }
        
        return ans;
    }
};