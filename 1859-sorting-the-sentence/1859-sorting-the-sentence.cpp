class Solution {
public:
    string sortSentence(string s) {
        int count = 1;
        
        // Counting spaces (no of words)
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') 
                count++;
        }

        vector<string> words(count);
        int index = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] >= '1' && s[i] <= '9') {
                int b = s[i] - '1';
                words[b] = s.substr(index, i-index);
                index = i + 2;
            }
        }

        string answer  = "";
        for(string str : words) {
            answer += str;
            answer += " ";
        }
        
        // Removing extra space
        answer.pop_back();
        return answer;
    }
};