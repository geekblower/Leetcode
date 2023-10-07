// class Solution {
// public:
//     bool isPalindrome(int x) {
//         int temp = x;
//         long long rev = 0;
        
//         while(temp) {
//             rev = (rev*10) + (temp%10);
//             temp /= 10;
//         }
        
//         return (x==rev && x>=0) ? true : false;
//     }
// };


class Solution {
public:
    bool isPalindrome(int x) {
        // int temp = x;
        long long int palindrome = 0;
        int num = x;
        
        while(x != 0) {
            long long int rem = x%10;
            palindrome = palindrome*10 + rem;
            x = x / 10;
        }
        
        if(palindrome == num && palindrome >= 0) {
            return true;
        } else {
            return false;
        }
    }
};