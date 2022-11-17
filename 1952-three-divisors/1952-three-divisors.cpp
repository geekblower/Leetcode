class Solution {
public:
    bool isThree(int n) {
        int x = sqrt(n);

        if(x*x != n || n < 4)
            return false;

        for(int i=2; i<=sqrt(x); i++) {
            if(x%i == 0)
                return false;
        }

        return true;
    }
};