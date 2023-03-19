class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        for(int i=0; i<words.size(); i++) {
            bool flag = true;
            string temp = words[i];

            for(int j=0; j<pref.length(); j++) {
                if(j>=temp.length() || pref[j]!=temp[j]) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                count++;
            }
        }

        return count;
    }
};