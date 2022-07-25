class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int itr1=a.size()-1;
        int itr2=b.size()-1;
        char carry='0';
        
        while(itr1>=0 || itr2>=0) {
            char ch1,ch2,sum;
            
            if(itr1<0)
                ch1='0';
            else {
                ch1=a[itr1];
                itr1--;
            }
            
            if(itr2<0)
                ch2='0';
            else {
                ch2=b[itr2];
                itr2--;
            }
            
            if(carry!=0)
                sum=ch1+ch2+carry-96;
            else
                sum=ch1+ch2-48;
            
            
            switch(sum) {
                case '0':
                    ans.push_back('0');
                    carry='0';
                    break;
                    
                case '1':
                    ans.push_back('1');
                    carry='0';
                    break;
                
                case '2':
                    ans.push_back('0');
                    carry='1';
                    break;
                
                case '3':
                    ans.push_back('1');
                    carry='1';
                    break;
            }            
        }
        
        if(carry=='1')
            ans.push_back('1');
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};