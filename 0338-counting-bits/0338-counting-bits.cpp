class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        
        for(int i=1; i<=n; i++) {
            int count = 0;
            int temp = i;
            
            while(temp != 0) {
                if(temp%2 == 1) count++;
                temp /= 2;
            }
            
            ans[i] = count;
        }
        
        return ans;
    }
};