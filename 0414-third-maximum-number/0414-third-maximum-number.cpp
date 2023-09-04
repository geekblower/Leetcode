class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int, bool> map;
        priority_queue<int> pq;
        
        for(int i=0; i<nums.size(); i++) {
            if(!map[nums[i]]) {
                pq.push(nums[i]);
                map[nums[i]] = true;
            }
        }
        
        if(pq.size() < 3)   return pq.top();

        pq.pop();
        pq.pop();
        return pq.top();
    }
};