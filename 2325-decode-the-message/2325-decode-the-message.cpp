class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,int> mp;
        int idx = 1;
        
        for(auto xx : key) {
            if(xx != ' ') {
                if(!mp[xx])
                    mp[xx] = idx++;
            }
        }
        
        string ans = "";
        
        for(auto xx : message) {
            if(xx == ' ')
                ans += ' ';
            else
                ans += ('a'+mp[xx]-1);
        }
        
        return ans;
    }
};