class Solution {
public:
    bool checkDigit(int num) {
        int temp = num;
        
        while(temp != 0) {
            int digit = temp % 10;
            temp /= 10;
            
            if(digit == 0) {
                return false;
            }
            
            if(num%digit != 0) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> answer;
        
        for(int i=left; i<=right; i++) {
            if(checkDigit(i)) {
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};