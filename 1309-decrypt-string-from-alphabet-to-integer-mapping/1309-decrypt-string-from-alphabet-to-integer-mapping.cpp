class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.length();
        string answer = "";
        
        for(int i=0; i<n; i++) {
            int num = s[i] - '0';
            
            if(i<n-2 && s[i+2]=='#') {
                num *= 10;
                num += (s[i+1]-'0');
                i += 2;
            }
            
            char ch = num + 96;
            answer += ch;
        }
        
        return answer;
    }
};