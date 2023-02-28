class Solution {
public:
    string addBinary(string a, string b) {

        string ans;
        int l1 = a.length() - 1;
        int l2 = b.length() - 1;
        int carry = 0;
        
        while(l1>=0 && l2>=0) {
            int sum = (a[l1--] - '0') + (b[l2--] - '0') + carry;

            if(sum >= 2) {
                carry = 1;
                sum -= 2;
            } else {
                carry = 0;
            }

            char ch = sum + '0';
            ans.push_back(ch);
        }

        while(l1>=0) {
            int sum = (a[l1--] - '0') + carry;

            if(sum >= 2) {
                carry = 1;
                sum -= 2;
            } else {
                carry = 0;
            }

            char ch = sum + '0';
            ans.push_back(ch);
        }

        while(l2>=0) {
            int sum = (b[l2--] - '0') + carry;

            if(sum >= 2) {
                carry = 1;
                sum -= 2;
            } else {
                carry = 0;
            }
            
            char ch = sum + '0';
            ans.push_back(ch);
        }

        char ch = carry + '0';
        ans.push_back(ch);

        for(int i=ans.length()-1; i>0; i++) {
            if(ans[i] == '0') {
                ans.pop_back();
            } else {
                break;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};