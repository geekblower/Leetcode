class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> solution;
        
        for(int i=1; i<n; i++) {
            int temp1=i, temp2=n-i;
            
            while(temp1) {
                if(temp1%10==0)
                    break;
                else
                    temp1 /= 10;
            }
            if(temp1%10==0 && temp1!=0)
                    continue;
            
            while(temp2) {
                if(temp2%10==0)
                    break;
                else
                    temp2 /= 10;
            }
            if(temp2%10==0 && temp2!=0)
                    continue;
            
            solution.push_back (i);
            solution.push_back (n-i);
            break;
        }
        
        return solution;
    }
};