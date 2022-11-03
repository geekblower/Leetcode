class Solution {
public:
    bool check(string s1, string s2, map<char, int> m) {
        if(s1==s2)
            return true;
        
        if(s1.find(s2)!=string::npos)
            return false;
        
        for(int i=0; i<s1.length() && i<s2.length(); i++) {
            if(m[s1[i]]>m[s2[i]]) {
                return false;
            }
        }

        return true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> m;
        int cnt = 1;
        
        for(int i=0; i<order.size(); i++) {
            m[order[i]] = cnt;
            cnt++;
        }
        
        for(int i=0; i<words.size()-1; i++) {
            if(m[words[i][0]]>m[words[i+1][0]])
                return false;
            else if(m[words[i][0]]==m[words[i+1][0]]) {
                if(!check(words[i],words[i+1],m))
                    return false;
            }
        }

        return true;
    }
};