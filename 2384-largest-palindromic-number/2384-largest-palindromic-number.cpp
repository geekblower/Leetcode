class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> res(10,0);
        
        for(int i=0; i<num.size(); i++){ 
            int temp = num[i]-'0';
            res[temp] += 1;
        }
        
        string ans = "";
        
        for(int i=9; i>=0; i--) { 
            if(res[i]) {
                if(res[i]>1) {
                    if(res[i]%2==0) {
                        int x = res[i]/2;
                        char y = '0' + i;
                        
                        while(x--)
                            ans += y;
                        
                        res[i] = 0; 
                    } else {
                        int x = res[i]-1;
                        res[i] = 1;
                        x /= 2;
                        char y = '0' + i;
                        
                        while(x--)
                            ans += y;
                    }
                }
            }
        }
        
        bool flag = false;
        for(int i=9; i>=0; i--) {
            char y = '0' + i; 
            
            if(res[i]==1) {
                ans += y; 
                flag = true; 
                break; 
            }
        }
        
        string temp;
        if(!flag) {
            temp = ans; 
            reverse(temp.begin(), temp.end()); 
            ans += temp;
        } else {
            temp = ans; 
            temp.pop_back(); 
            reverse(temp.begin(), temp.end()); 
            ans += temp; 
        }
        
        int cnt = 0; 
        for(int i=0; i<ans.size(); i++) {
            if(ans[i]=='0')
                cnt++;
            else 
                break; 
        }
         
        if(cnt>0) {
            int te = cnt; 
            
            while(te--)
                ans.pop_back();
            
            te = cnt;
            ans.erase(0, cnt); 
        }
        
        if(ans.size()==0)
            return "0"; 
        
        return ans;
    }
};