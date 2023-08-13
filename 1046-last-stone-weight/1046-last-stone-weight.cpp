class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int i=0; i<stones.size(); i++) {
            maxHeap.push(stones[i]);
        }

        while(maxHeap.size() > 1) {
            int top1 = maxHeap.top();
            maxHeap.pop();
            int top2 = maxHeap.top();
            maxHeap.pop();

            if(top1 > top2) {
                maxHeap.push(top1-top2);
            }
        }

        return (maxHeap.size() == 0) ? 0 : maxHeap.top();
    }
};