class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int rem = purchaseAmount%10;
        return (rem < 5) ? 100 - (purchaseAmount/10)*10 : 100 - (purchaseAmount/10+1)*10;
    }
};