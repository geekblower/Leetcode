class Solution {
public:
    int titleToNumber(string columnTitle) {
        int answer = 0;
        long long n = 1;
        
        for(int i = columnTitle.length()-1; i>=0; i--) {
            int curr = columnTitle[i] - 'A' + 1;
            answer += (curr * n);
            n *= 26;
        }
        
        return answer;
    }
};