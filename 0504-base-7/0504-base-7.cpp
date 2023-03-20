class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) {
            return "0";
        }
        
        string answer;
        bool flag = (num < 0) ? true : false;
        num = (num < 0) ? -1 * num : num;

        while(num) {
            int digit = num % 7;
            answer.push_back (digit + '0');
            num /= 7;
        }

        if(flag) {
            answer.push_back ('-');
        }

        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};