class Solution {
public:
    void solve(vector<vector<int>> &answer, vector<int>& candidates, vector<int> curr, int sum, int target) {
        if(sum == target) {
            sort(curr.begin(), curr.end());

            for(int i=0; i<answer.size(); i++) {
                if(answer[i] == curr) {
                    return;
                }
            }
            
            answer.push_back(curr);
            return;
        }

        for(int i=0; i<candidates.size(); i++) {
            sum += candidates[i];

            if(sum > target) {
                return;
            }

            curr.push_back(candidates[i]);
            solve(answer, candidates, curr, sum, target);
            curr.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());

        solve(answer, candidates, curr, 0, target);
        return answer;    
    }
};