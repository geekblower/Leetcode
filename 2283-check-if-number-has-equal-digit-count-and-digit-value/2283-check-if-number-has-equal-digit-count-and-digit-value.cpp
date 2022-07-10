class Solution {
public:
    bool digitCount(string num) {
        for(int i=0; i<num.length(); i++) {
            char ch = i + 48;
            int start = 0, end = num.length()-1;
            int count = 0;
            
            while(start < end) {
                if(num[start] == ch)
                    count++;
                if(num[end] == ch)
                    count++;
                start++;
                end--;
            }
            
            if(num[start] == ch && start == end)            // Extra case of start==end to avoid double counting
                    count++;
            
            ch = count + 48;            // Assinging counted value to 'ch' in numerical form
            
            if(ch != num[i])
                return false;
        }
        
        return true;
    }
};