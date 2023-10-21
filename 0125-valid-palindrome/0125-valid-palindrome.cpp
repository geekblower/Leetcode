class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        
        for(int i=0; i<s.length(); i++) {
            // Uppercase
            if(s[i]>='A' && s[i]<='Z') temp += tolower(s[i]);
            
            // Lowercase
            if(s[i]>='a' && s[i]<='z') temp += s[i];
            
            // Numbers
            if(s[i]>='0' && s[i]<='9') temp += s[i];
        }
        
        int start = 0;
        int end = temp.length()-1;
        
        while(start < end) {
            if(temp[start] != temp[end]) return false;
            
            start++;
            end--;
        }
        
        return true;
    }
};