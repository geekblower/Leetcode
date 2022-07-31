class Solution {
    public:
        const int MOD = 1000000007;
    
        long int fact(long int a) {
            if(a<=1)
                return 1;
            
            long int f=a;
            f *= fact(a-1);
            
            return f % MOD;
        }
    
    int numPrimeArrangements(int n) {
        int i;
        long int composites=0, primes=0;
        int prime[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        
        for(i=0; i<25; i++)
            if(n >= prime[i])
                primes++;
        
        composites = n-primes;
        return (fact(primes) * fact(composites)) % MOD;
    }
};