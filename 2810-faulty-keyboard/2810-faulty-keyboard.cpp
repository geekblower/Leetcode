class Solution {
public:
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