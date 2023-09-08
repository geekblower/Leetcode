class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;
        
        // Step 0 : Creating the queues
        queue<pair<int,int>> month;
        queue<pair<int,int>> week;
        
        for(int d : days) {
            // Step 1 : Removing the expired days
            while(!month.empty() && month.front().first + 30 <= d) {
                month.pop();
            }
            
            while(!week.empty() && week.front().first + 7 <= d) {
                week.pop();
            }
            
            // Step 2 : Pushing current day
            month.push({d, ans+costs[2]});
            week.push({d, ans+costs[1]});
            
            // Step 3 : Updating answer
            ans = min(ans+costs[0], min(month.front().second, week.front().second));
        }
        
        return ans;
    }
};