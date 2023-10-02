class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.length() <= 2) return false;
        int a=0, b=0;
        
        for(int i=0; i<colors.length()-2; i++) {
            if(colors[i]=='A' && colors[i+1]=='A' && colors[i+2]=='A') a++;
            if(colors[i]=='B' && colors[i+1]=='B' && colors[i+2]=='B') b++;
        }
        
        return a > b;
    }
};