class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> m;

        while(1) {
            int ans = 0;

            while(n != 0) {
                int digit = n % 10;
                ans += (digit * digit);
                n = n / 10;
            }

            if(ans == 1)
                return true;
            else if(m[ans] == true)
                return false;
            else {
                m[ans] = true;
                n = ans;
            }
        }

        return false;
    }
};