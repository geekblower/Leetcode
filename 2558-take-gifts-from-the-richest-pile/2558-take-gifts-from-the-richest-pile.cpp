class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap;
        for(int i=0; i<gifts.size(); i++) {
            maxHeap.push(gifts[i]);
        }

        for(int i=0; i<k; i++) {
            int top = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(sqrt(top));
        }

        long long sum = 0;
        while(!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }

        return sum;
    }
};