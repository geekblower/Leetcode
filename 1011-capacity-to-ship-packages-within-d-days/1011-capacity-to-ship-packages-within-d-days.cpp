class Solution {
public:
    bool isPossible(vector<int> weights, int days, int mid) {
        int count = 1, weight = 0;
        
        for(int i=0; i<weights.size(); i++) {
            if(weight + weights[i] <= mid) {
                weight += weights[i];
            } else {
                count++;
                weight = 0;
                if(weights[i] > mid || count > days) {
                    return false;
                }
            weight += weights[i];
            }
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int i=0; i<weights.size(); i++) {
            sum += weights[i];
        }
        int start = 0;
        int end = sum;
        int ans = 0;
        
        while(start <= end) {
            int mid = start + (end - start)/2;

            if(isPossible(weights, days, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
};