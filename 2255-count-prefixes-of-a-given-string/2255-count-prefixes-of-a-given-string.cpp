class Solution {
public:
    bool check(string str, string s) {
        int size = str.size();
        for(int i=0; i<size; i++) {
            if(str[i] != s[i])
                return false;
        }
        return true;
    }
    
    int countPrefixes(vector<string>& words, string s) {
        int ans=0;
        for(int i=0; i<words.size(); i++) {
            if(check(words[i], s))
                ans++;
        }
        return ans;
    }
};