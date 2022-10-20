class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        
        if(num>=1000) {
            int x = num/1000;
            while(x--)
                ans += "M";
            num %= 1000;
        }
        
        if(num>=900) {
            ans += "CM";
            num -= 900;
        }
        
        if(num>=500) {
            ans += "D";
            num -= 500;
        }
        
        if(num>=400) {
            ans += "CD";
            num -= 400;
        }
        
        if(num>=100) {
            int x = num/100;
            while(x--)
                ans += "C";
            num %= 100;
        }
        
        if(num>=90) {
            ans += "XC";
            num -= 90;
        }
        
        if(num>=50) {
            ans += "L";
            num -= 50;
        }
        
        if(num>=40) {
            ans += "XL";
            num -= 40;
        }
        
        if(num>=10) {
            int x = num/10;
            while(x--)
                ans += "X";
            num %= 10;
        }
        
        if(num>=9) {
            ans += "IX";
            num -= 9;
        }
        
        if(num>=5) {
            ans += "V";
            num -= 5;
        }
        
        if(num>=4) {
            ans += "IV";
            num -= 4;
        }
        
        if(num>=1) {
            int x = num/1;
            while(x--)
                ans += "I";
            num %= 1;
        }
        
        return ans;
    }
};