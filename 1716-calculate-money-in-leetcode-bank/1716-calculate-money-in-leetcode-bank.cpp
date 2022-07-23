class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        
        for(int i=0; i<n; i++)
            total += (i%7) + (i/7) + 1;
        
        return total;
    }
};