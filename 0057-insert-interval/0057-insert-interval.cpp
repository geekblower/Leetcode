class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back (newInterval);
        int i = intervals.size() - 1;
        int count = 0;
        
        for(; i>0; i--) {
            if(intervals[i][1] < intervals[i-1][0])
                swap(intervals[i], intervals[i-1]);
            else if(intervals[i][0] > intervals[i-1][1])
                break;
            else {
                intervals[i-1][0] = min(intervals[i-1][0], intervals[i][0]);
                intervals[i-1][1] = max(intervals[i-1][1], intervals[i][1]);
                count++;
            }
        }
        
        i++;
        
        if(count) {
            int len = intervals.size();
            
            while(i != len){
                if(i+count < len)
                    swap(intervals[i], intervals[i+count]);
                else
                    intervals.pop_back();
                
                i++;
            }
        }
        
        return intervals;
    }
};