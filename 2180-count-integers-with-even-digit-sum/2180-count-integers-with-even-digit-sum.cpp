class Solution {
public:
    bool isEven(int n) {
        long long int sum = 0;
        while(n) {
            sum += (n%10);
            n /= 10;
        }
        
        if(sum&1)
            return false;
        else
            return true;
    }
    
    int countEven(int num) {
        int count=0;
        
        for(int i=1; i<=num; i++) {
            if(isEven(i))
                count++;
        }
        
        return count;
    }
};