class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string ans = to_string(num);
        int count = 0;
        
        for(int i=0; i<ans.length()-k+1; i++) {
            int new_num = 0;
            for(int j=i; j<i+k; j++) {
                int c = (int) ans[j];
                new_num = (new_num*10) + (c-48);
            }
            
            if(new_num == 0)
                continue;
            
            if(num % new_num == 0)
                count++;
        }
        
        return count;
    }
};