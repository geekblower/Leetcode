class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;

        for(int i=0; i<boxes.length(); i++) {
            int tot = 0;

            for(int j=0; j<boxes.length(); j++) {
                if(j!=i && boxes[j]=='1') {
                    tot += abs(j-i);
                }
            }

            ans.push_back(tot);
        }

        return ans;
    }
};