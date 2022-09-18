class Solution {
public:
    string reformatNumber(string number) {
        string answer = "";
        int count = 0;
        
        for(int i=0; i<number.size(); i++) {
            if(number[i]==' ' || number[i]=='-')
                continue;
            
            answer += number[i];
            count++;
            
            if(count == 3) {
                answer += "-";
                count = 0;
            }
        }
        int n = answer.length();
        
        if(count == 1) {
            char temp = answer[n-2];
            answer[n-2] = answer[n-3];
            answer[n-3] = temp;
        }
        
        if(answer[n-1] == '-')
            answer.pop_back();
        
        return answer;
    }
};