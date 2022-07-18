class Solution {
public:
    void reverse(string &s, int start, int end) {
        while(start < end) {
            char ch = s[start];
            s[start] = s[end];
            s[end] = ch;
            start++;
            end--;
        }
    }
    
    string reverseWords(string s) {
        int start = 0, end = 0;
        
        while(end < s.length()) {
            while(s[end] != ' ' && end < s.length())
                end++;
            reverse(s, start, end-1);
            end++;
            start = end;
        }
        
        return s;
    }
};