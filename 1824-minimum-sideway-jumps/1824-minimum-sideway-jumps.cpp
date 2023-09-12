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
    
    int solveTab(vector<int> &obs) {
        int n = obs.size() - 1;   
        vector<vector<int>> dp(4, vector<int>(obs.size(), 1e9));
        
        dp[0][n] = dp[1][n] = dp[2][n] = dp[3][n] = 0;
        
        for(int pos=n-1; pos>=0; pos--) {
            for(int lane=1; lane<=3; lane++) {
                if(obs[pos+1] != lane) {
                    dp[lane][pos] = dp[lane][pos+1];
                } else {

                    // SIDEWAYS JUMP
                    int ans = 1e9;
                    for(int i=1; i<=3; i++) {
                        if(lane != i && obs[pos] != i) {
                            ans = min(ans, 1 + dp[i][pos+1]);
                        }
                    }

                    dp[lane][pos] = ans;
                }
            }
        }
        
        return min(dp[2][0], min(dp[1][0]+1, dp[3][0]+1));
    }
    
    int solveSpc(vector<int> &obs) {
        int n = obs.size()-1;
        vector<int> curr(4, 1e9);
        vector<int> next(4, 0);
        
        for(int pos=n-1; pos>=0; pos--) {
            for(int lane=1; lane<=3; lane++) {
                if(obs[pos+1] != lane) {
                    curr[lane] = next[lane];
                } else {

                    // SIDEWAYS JUMP
                    int ans = 1e9;
                    for(int i=1; i<=3; i++) {
                        if(lane != i && obs[pos] != i) {
                            ans = min(ans, 1 + next[i]);
                        }
                    }

                    curr[lane] = ans;
                }
            }
            
            next = curr;
        }
        
        return min(next[2], min(next[1]+1, next[3]+1));
    }
    
    int minSideJumps(vector<int>& obstacles) {
        // return solveRec(obstacles, 0, 2);
        
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        // return solveMem(dp, obstacles, 0, 2);
        
        // return solveTab(obstacles);
        
        return solveSpc(obstacles);
    }
};