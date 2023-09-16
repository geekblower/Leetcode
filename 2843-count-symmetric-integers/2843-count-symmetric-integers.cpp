class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        
        for(int i=low; i<=high; i++) {
            string str = to_string(i);
            if(str.length() & 1) continue;
            
            int length = str.length() / 2;
            int sum1=0, sum2=0;
            
            for(int j=0; j<str.length(); j++) {
                if(length > 0) {
                    sum1 += (str[j] - '0');
                    length--;
                } else {
                    sum2 += (str[j] - '0');
                }
            }
            
            if(sum1 == sum2) count++;
        }
        
        return count;
    }
};