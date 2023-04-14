class Solution {
    public:
    int countOdds(int low, int high) {
        int count = 0;

        if(low%2 == 1) {
            count++;
            low += 2;
        } else {
            low++;
        }
        
        while(low <= high) {
            count++;
            low += 2;
        }

        return count;
    }
};