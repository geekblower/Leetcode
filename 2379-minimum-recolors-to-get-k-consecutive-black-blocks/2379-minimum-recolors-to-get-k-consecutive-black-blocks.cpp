class Solution {
public:
    int minimumRecolors(string v, int k) {
        int maximum=0;
        
        for(int i=0; i<=v.size()-k; i++) {
            int count=0;
            
            for(int j=i; j<k+i; j++) {
                if(v[j] == 'B')
                    count++;
            }
            
            maximum = max(maximum, count);
        }
        
        return (k-maximum);
    }
};