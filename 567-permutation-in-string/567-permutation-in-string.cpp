class Solution {
public:
    void updateV2(vector<int>& v2, int n, int i, string &s2) {
        v2[s2[i-n]-'a']--;
        v2[s2[i]-'a']++;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        vector<int> v1(26, 0), v2(26, 0);
        int n = s1.size();
        
        for(int i=0; i<s1.size(); i++) {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        
        if(v1 == v2)
            return true;
        
        for(int i=n; i<s2.size(); i++) {
            updateV2(v2, n, i, s2);
            if(v2 == v1)
                return true;
        }
        
        return false;
    }
};