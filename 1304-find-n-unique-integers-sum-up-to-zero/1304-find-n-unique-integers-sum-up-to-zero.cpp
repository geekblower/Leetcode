class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> solution;
        int sum = 0;
        
        for(int i=1; i<=n-1; i++) {
            solution.push_back (i);
            sum += i;
        }
        
        solution.push_back (-sum);
        
        return solution;
    }
};