class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        for(int i=0; i<=30; i++) {
            int x = pow(2,i);
            if(x>left && x<=right) return 0;
        }

        int ans = left;
        
        for(int i=ans; i<=right; i++) {
            ans = ans & i;
            if(i == INT_MAX) break;
        }
        
        return ans;
    }
};