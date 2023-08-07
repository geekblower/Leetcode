class Solution {
public:
    void solve(vector< vector<int> > &solution, vector<int> answer, int n, int k, int x) {
        if(answer.size() == k) {
            solution.push_back(answer);
            return;
        }

        while(x <= n) {
            answer.push_back(x);
            x++;
            solve(solution, answer, n, k, x);
            answer.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector< vector<int> > solution;
        vector<int> answer;

        solve(solution, answer, n, k, 1);

        return solution;
    }
};