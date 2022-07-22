class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum = INT_MIN;
        vector<bool> ans;
        
        for(auto &i:candies)
            maximum = max(i, maximum);
        
        for(int i=0; i<candies.size(); i++) {
            if(candies[i]+extraCandies >= maximum)
                ans.push_back (true);
            else
                ans.push_back (false);
        }
        
        return ans;
    }
};