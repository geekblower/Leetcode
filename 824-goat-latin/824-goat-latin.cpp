class Solution {
public:
    void convert(string str, string &ans, int s, int e, int count) {
        if(str[s]=='a' || str[s]=='A' || str[s]=='e' || str[s]=='E' || str[s]=='i' || str[s]=='I' || str[s]=='o' || str[s]=='O' || str[s]=='u' || str[s]=='U') {
            for(int i=s; i<e; i++)
                ans.push_back (str[i]);
            
            ans += "ma";
        } else {
            for(int i=s+1; i<e; i++)
                ans.push_back (str[i]);
            
            ans.push_back (str[s]);
            ans += "ma";
        }
        
        while(count--)
            ans.push_back ('a');
        
        ans += " ";
    }
    
    string toGoatLatin(string sentence) {
        int n = sentence.length();
        string answer;
        
        int start=0, end=0, count=1;
        while(end<n) {
            while(sentence[end] != ' ' && end<n)
                end++;
            
            convert(sentence, answer, start, end, count);
            
            count++;
            end++;
            start = end;
        }
        
        answer.pop_back();
        return answer;
    }
};