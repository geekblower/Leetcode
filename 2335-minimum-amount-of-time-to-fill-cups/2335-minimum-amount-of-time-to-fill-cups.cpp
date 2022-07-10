class Solution {
public:
    int fillCups(vector<int>& amount) {
        int maximum = (amount[0]>amount[1] && amount[0]>amount[2]) ? amount[0] : (amount[1]>amount[2] ? amount[1] : amount[2]);
        int sum = amount[0] + amount[1] + amount[2];
        int ans = (sum+1)/2;
        return (ans>maximum) ? ans : maximum;
    }
};