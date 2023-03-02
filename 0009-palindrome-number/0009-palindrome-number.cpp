class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long rev = 0;
        
        while(temp) {
            rev = (rev*10) + (temp%10);
            temp /= 10;
        }
        
        return (x==rev && x>=0) ? true : false;
    }
};