class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        if(digits.size()==0)
            return result;
        
        string charmap[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        result.push_back("");
        
        for(int i=0; i<digits.size(); i++) {
            vector<string> temp;
            string chars = charmap[digits[i] - '0'];
            for(int c=0; c<chars.size(); c++) {
                for(int j=0; j<result.size(); j++)
                    temp.push_back(result[j] + chars[c]);
            }
            result=temp;
        }
        
        return result;
    }
};