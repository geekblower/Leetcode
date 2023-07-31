class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()) {
            return -1;
        }
        
        int len1 = haystack.length();
        int len2 = needle.length();
        
        for(int i=0; i<len1-len2+1; i++) {
            
            if(haystack[i] != needle[0]) {
                continue;
            }
            
            int temp = i, j = 0;
            bool match = true;
            
            while(temp<len1 && j<len2) {
                if(haystack[temp] != needle[j]) {
                    match = false;
                    break;
                }
                
                temp++;
                j++;
            }
            
            if(match) {
                return i;
            }
        }
        
        return -1;
    }
};