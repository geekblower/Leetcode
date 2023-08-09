class Solution {
public:
void solve(vector<vector<int>> &answer, vector<int>& candidates, vector<int> curr, int sum, int target, int index) {
        if(sum == target) {
            answer.push_back(curr);
            return;
        }

        for(int i=index; i<candidates.size(); i++) {
            int pick = candidates[i];

            if(sum+pick > target) {
                break;
            }

            if(i > index && candidates[i] == candidates[i-1]) {
                continue;
            }
            
            curr.push_back(candidates[i]);
            solve(answer, candidates, curr, sum+pick, target, i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());

        int sum = 0;
        for(int x : candidates) {
            sum += x;
        }

        if(sum < target) {
            return {};
        }

        if(sum == target) {
            answer.push_back(candidates);
            return answer;
        }

        solve(answer, candidates, curr, 0, target, 0);
        return answer;    
    }
};