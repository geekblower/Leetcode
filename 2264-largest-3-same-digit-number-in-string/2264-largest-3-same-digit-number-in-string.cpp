class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char ans=0;
        
        for(int i=0; i<n-2; i++) {
            if((num[i] == num[i+1]) && (num[i+1] == num[i+2])) {
                if(num[i] > ans)
                    ans = num[i];
            }
        }
        
        if(ans == 0)
            return "";
        else
            return string(3, ans);
    }
};