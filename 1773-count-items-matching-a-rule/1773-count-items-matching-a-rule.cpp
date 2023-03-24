class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        int index = 2;
        
        if(ruleKey == "type") {
            index = 0;
        } else if(ruleKey == "color") {
            index = 1;
        }

        for(int i=0; i<items.size(); i++) {
            if(items[i][index] == ruleValue) {
                count++;
            }
        }

        return count;
    }
};