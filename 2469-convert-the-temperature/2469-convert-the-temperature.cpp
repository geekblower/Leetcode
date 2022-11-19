class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> answer;
        
        answer.push_back (celsius + 273.15);
        answer.push_back (celsius * 1.80 + 32.00);
        
        return answer;
    }
};