class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freqMap(26);
        
        for(char c:s)
            freqMap[c - 'a']++;
        
        int n = s.length();
        
        for(int i=0; i<n; i++) {
            if(freqMap[s[i]-'a'] == 1)
                return i;
        }
        
        return -1;
    }
};