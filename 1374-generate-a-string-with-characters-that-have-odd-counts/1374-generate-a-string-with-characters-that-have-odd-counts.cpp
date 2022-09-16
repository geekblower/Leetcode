class Solution {
public:
    string generateTheString(int n) {
        string answer = "";
        
        if(n&1) {
            for(int i=0; i<n; i++)
                answer += "a";
        } else {
            for(int i=0; i<n-1; i++)
                answer += "a";
            answer += "b";
        }
        
        return answer;
    }
};