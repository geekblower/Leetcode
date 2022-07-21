class Solution {
public:
    int maximum69Number (int num) {
        vector<int> numbers;
        int temp = num;
        
        while(temp) {
            numbers.push_back (temp%10);
            temp /= 10;
        }
        
        reverse(numbers.begin(), numbers.end());
        
        for(int i=0; i<numbers.size(); i++) {
            if(numbers[i]==6) {
                int x = numbers.size()-i-1;
                x = pow(10, x);
                num += (x*3);
                return num;
            }
        }
        
        return num;
    }
};