class Solution {
public:
    int subtractProductAndSum(int n) {
        int temp = n;
        int pro = 1, sum = 0; 
        
        while(temp) {
            pro *= (temp%10);
            sum += (temp%10);
            temp /= 10;
        }
        
        return pro-sum;
    }
};