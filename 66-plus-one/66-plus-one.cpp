class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int num = 1, i;
        
        for(i=n-1; i>=0; i--) {
            int temp = digits[i];
            temp += num;
            if(temp<10) {
                digits[i] = temp;
                break;
            }
            num = temp / 10;
            digits[i] = temp % 10;
        }
        
        if(i<0)
            digits.insert(digits.begin(), num);
        
        return digits;
    }
};