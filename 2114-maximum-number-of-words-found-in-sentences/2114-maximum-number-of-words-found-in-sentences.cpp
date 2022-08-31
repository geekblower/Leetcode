class Solution {
public:
    int countWords(string str) {
        int n = str.length();
        int count = 1;
        
        for(int i=0; i<n; i++) {
            if(str[i] == ' ')
                count++;
        }
        
        return count;
    }
    
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        
        for(int i=0; i<sentences.size(); i++) {
            int temp = countWords(sentences[i]);
            ans = max(temp, ans);
        }
        
        return ans;
    }
};