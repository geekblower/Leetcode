class Solution {
public:
    bool selfDividing(int n) {
        int temp = n;
        while(temp) {
            int digit = temp%10;
            if(digit==0 || n%digit!=0)
                return false;
            temp /= 10;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        
        for(int i=left; i<=right; i++) {
            if(selfDividing(i))
                ans.push_back (i);
        }
        
        return ans;
    }
};