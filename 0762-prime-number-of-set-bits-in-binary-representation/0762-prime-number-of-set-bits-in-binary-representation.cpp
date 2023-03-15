class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int total = 0;

        for(int i=left; i<=right; i++) {
            int temp = i;
            int bits = 0;
            bool prime = true;

            while(temp) {
                bits += (temp&1);
                temp >>= 1;
            }

            for(int j=2; j<=sqrt(bits); j++) {
                if(bits%j == 0) {
                    prime = false;
                    break;
                }
            }

            if(prime && bits>1) {
                total++;
            }
        }

        return total;
    }
};