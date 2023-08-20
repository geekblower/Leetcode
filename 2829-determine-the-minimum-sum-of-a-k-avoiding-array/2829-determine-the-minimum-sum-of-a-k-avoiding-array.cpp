class Solution {
public:
    int minimumSum(int n, int k) {
        vector<bool> map(3*n, true);
        
        int size = 0;
        int sum = 0;
        int count = 1;
        
        while(size < n) {
            if(map[count]) {
                sum += count;
                if(count <= k) map[k-count] = false;
                size++;
            }
            count++;
        }

        return sum;
    }
};