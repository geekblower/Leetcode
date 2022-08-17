class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> t = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> s;
        for(int i=0; i<words.size();i++) {
            string tt = words[i];
            string temp = "";

            for(int j=0; j<tt.length(); j++) {
                int e = tt[j] - 'a';
                temp += t[e];
            }
            
            s.insert(temp);
        }
        
        return s.size();
    }
};