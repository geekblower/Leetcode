class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string answer = "";
        
        for(int i=0; i<n; i++) {
            if(s[i] != s[i+1]) {
                answer.push_back (s[i]);
            } else {
                answer.push_back (s[i]);
                answer.push_back (s[i+1]);
                i++;
                
                while(s[i]==s[i+1] && i<n)
                    i++;    
            }
        }
        
        return answer;
    }
};