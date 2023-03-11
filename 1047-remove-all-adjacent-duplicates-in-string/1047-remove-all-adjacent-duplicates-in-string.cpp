class Solution {
public:
    string removeDuplicates(string s) {
        string solution;

        for(int i=0; i<s.length(); i++) {
            int len = solution.length();

            if(len == 0) {
                solution.push_back (s[i]);
            } else {
                if(solution[len-1] == s[i]) {
                    solution.pop_back();
                } else {
                    solution.push_back (s[i]);
                }
            }
        }

        return solution;
    }
};