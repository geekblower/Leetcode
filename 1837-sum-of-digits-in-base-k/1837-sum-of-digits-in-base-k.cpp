class Solution {
public:
    int reverse(int n) {
        int ans = 0;
        while(n) {
            ans *= 10;
            ans += (n%10);
            n /= 10;
        }
        return ans;
    }
    
    int sumBase(int n, int k) {
        int temp=n, newNum=0;
        
        while(temp) {
            newNum *= 10;
            newNum += (temp%k);
            temp /= k;
        }
        
        newNum = reverse(newNum);
        
        int sum = 0;
        while(newNum) {
            sum += (newNum%10);
            newNum /= 10;
        }
        
        return sum;
    }
};