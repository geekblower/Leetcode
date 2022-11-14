class Solution {
public:
    bool isSameAfterReversals(int num) {
        return (num%10 || num==0) ? true : false;
    }
};