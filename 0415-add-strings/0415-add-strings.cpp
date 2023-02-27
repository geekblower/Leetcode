class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        string solution;

        while(i>=0 && j>=0) {
            int value = (num1[i--] - '0') + (num2[j--] - '0') + carry;

            char ch = (value%10) + '0';
            solution.push_back (ch);
            carry = value / 10;
        }

        while(i>=0) {
            int value = (num1[i--] - '0') + carry;

            char ch = (value%10) + '0';
            solution.push_back (ch);
            carry = value / 10;
        }

        while(j>=0) {
            int value = (num2[j--] - '0') + carry;

            char ch = (value%10) + '0';
            solution.push_back (ch);
            carry = value / 10;
        }

        while(carry > 0) {
            char ch = (carry%10) + '0';
            solution.push_back (ch);
            carry = carry / 10;
        }

        reverse(solution.begin(), solution.end());
        return solution;
    }
};