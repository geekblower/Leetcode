class Solution {
public:
    string replaceDigits(string s) {
        string sol;
        
        for(int i=0; i<s.length(); i+=2) {
            sol += s[i];
            if(i < s.length()-1) sol += (s[i] + (s[i+1]-'0'));
        }
        
        return sol;
    }
};