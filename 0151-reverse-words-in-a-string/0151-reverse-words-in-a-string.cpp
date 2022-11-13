class Solution {
public:
    string reverseWords(string s) {
        string answer = "";
        reverse(s.begin(), s.end());
        
        for(int i=0; i<s.length(); i++) {
            string temp = "";
            
            while(s[i]!=' ' && i<s.length()) {
                char ch = s[i];
                temp += ch;
                i++;
            }
            
            while(i<s.length()-1 && s[i+1]==' ') {
                i++;
            }
            
            reverse(temp.begin(), temp.end());
            answer += temp;
            
            if(i!=s.length() && temp!="")
                answer += " ";
        }
        
        for(int i=answer.length()-1; i>=0; i--) {
            if(answer[i] == ' ')
                answer.pop_back();
            else
                break;
        }
        
        return answer;
    }
};