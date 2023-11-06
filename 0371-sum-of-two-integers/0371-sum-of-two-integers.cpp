// class Solution {
// public:
//     int getSum(int a, int b) {
//         int carry=0, sum=0, temp=1;
        
//         while(a!=0 || b!=0) {
//             int currbit=0;
            
//             if((a&1) != (b&1)) {
//                 // Unequal bits
//                 currbit = 1;
//                 if(carry) currbit = 0;
//             } else {
//                 // Equal bits
//                 if(a&1) {
//                     // Both bits are 1
//                     currbit = (carry) ? 1 : 0;
//                     carry = 1;
//                 } else {
//                     // Both bits are 0
//                     currbit = carry;
//                     carry = 0;
//                 }
//             }
            
//             temp = 
             
            
//             a = a >> 1;
//             b = b >> 1;
            
//         }
        
//         return sum;
//     }
// };

class Solution {
public:
    int getSum(int a, int b) {
        if(b>0)
            for(int i=0; i<b; i++) a++;
        else
            for(int i=0; i>b; i--) a--;

        return a;
    }
};
