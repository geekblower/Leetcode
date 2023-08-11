class Solution {
public:
    string rev(string s) {
        int start = 0;
        int end = s.length() - 1;
        return s;
    }
    
    string finalString(string s) {
        
        string answer = "";
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'i') {
                reverse(answer.begin(), answer.end());
            } else {
                answer += s[i];
            }
        }
        
        return answer;
        
    }
};