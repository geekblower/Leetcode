// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int count_set_bit(int n) {
        int ans = 0;
        
        while(n) {
            if(n%2 == 1)
                ans++;
            n /= 2;
        }
        
        return ans;
    }
    
    int minVal(int a, int b) {
        vector<int> a_bits(32,0);
        int on = 0;
        int i = 0;
        
        while(a) {
            a_bits[i] = a%2;
            i++;
            
            if(a%2 == 1)
                on++;
            
            a /= 2;
        }
        
        int cnt = count_set_bit(b);
        int res = 0;
        
        if(cnt>on) {
            cnt = cnt - on;
            
            for(int i=0; i<a_bits.size(); i++){
                if(cnt == 0)
                    break;
                
                if(a_bits[i] == 0){
                    a_bits[i] = 1;
                    cnt--;
                }
            }
            
        } else {
            cnt = on - cnt;
            
            for(int i=0; i<a_bits.size(); i++){
                if(cnt == 0)
                    break;
                
                if(a_bits[i] == 1){
                    a_bits[i] = 0;
                    cnt--;
                }
            }
            
        }
        
        int p=0;
        
        for(int i=0; i<a_bits.size(); i++){
            res += a_bits[i] * pow(2,p);
            p++;
        }
        
        return res;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends