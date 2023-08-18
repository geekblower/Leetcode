class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> solution(encoded.size()+1, 0);
        solution[0] = first;
        
        for(int i=0; i<encoded.size(); i++) {
            solution[i+1] = encoded[i] ^ solution[i];
        }
        
        return solution;
    }
};