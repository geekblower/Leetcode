class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string solution = "";
        
        for(int i=0; i<strs[0].length(); i++) {
            
            char curr = strs[0][i];
            bool flag = false;
            
            for(int j=0; j<strs.size(); j++) {
                if(strs[j][i] != curr) {
                    flag = true;
                    break;
                }
            }
            
            if(flag) return solution;
            
            solution += curr;
            
        }
        
        return solution;
        
    }
};