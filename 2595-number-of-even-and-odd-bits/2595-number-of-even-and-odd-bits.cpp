class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even=0, odd=0;
        bool E=1;

        while(n) {
            if(n&1) {
                if(E) {
                    even++;
                } else {
                    odd++;
                }
            }

            n = n >> 1;
            E = !E;
        }

        return {even, odd};
    }
};