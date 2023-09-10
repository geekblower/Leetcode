class Solution {
public:
    int solveRec(vector<int> &obs, int pos, int lane) {
        if(pos == obs.size()-1) {
            return 0;
        }
        
        if(obs[pos+1] != lane) {
            return solveRec(obs, pos+1, lane);
        } else {
            
            // SIDEWAYS JUMP
            int ans = INT_MAX;
            for(int i=1; i<=3; i++) {
                if(lane != i && obs[pos] != i) {
                    ans = min(ans, 1 + solveRec(obs, pos, i));
                }
            }
            
            return ans;
        }
    }
    
    int solveMem(vector<vector<int>> &dp, vector<int> &obs, int pos, int lane) {
        if(pos == obs.size()-1) {
            return 0;
        }
        
        if(dp[lane][pos] != -1) {
            return dp[lane][pos];
        }
        
        if(obs[pos+1] != lane) {
            return solveMem(dp, obs, pos+1, lane);
        } else {
            
            // SIDEWAYS JUMP
            int ans = INT_MAX;
            for(int i=1; i<=3; i++) {
                if(lane != i && obs[pos] != i) {
                    ans = min(ans, 1 + solveMem(dp, obs, pos, i));
                }
            }
            
            dp[lane][pos] = ans;
            return ans;
        }
    }
    
    int minSideJumps(vector<int>& obstacles) {
        // return solveRec(obstacles, 0, 2);
        
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        return solveMem(dp, obstacles, 0, 2);
    }
};