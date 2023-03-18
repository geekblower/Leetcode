class Solution {
public:
    string defangIPaddr(string address) {
        string output;

        for(int i=0; i<address.length(); i++) {
            if(address[i] == '.') {
                output += "[.]";
            } else {
                output.push_back(address[i]);
            }
        }

        return output;
    }
};