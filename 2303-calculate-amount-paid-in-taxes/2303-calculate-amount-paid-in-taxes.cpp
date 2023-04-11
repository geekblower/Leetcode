class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int limit = brackets[0][0];
        int balance = (limit <= income) ? limit : income;
        income -= limit;
        double tax = (double) balance * ((double) brackets[0][1] / 100);

        for(int i=1; i<brackets.size(); i++) {
            if(income <= 0) {
                break;
            }
            
            limit = brackets[i][0] - brackets[i-1][0];
            balance = (limit <= income) ? limit : income;
            income -= limit;
            
            tax += (double) balance * ((double) brackets[i][1] / 100);
        }

        return tax;
    }
};