class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;

        for(int i=0; i<chars.size(); i++) {
            int count = 0;
            char temp = chars[i];

            while(i<chars.size() && chars[i]==temp) {
                i++;
                count++;
            }
            i--;

            ans.push_back(temp);
            if(count > 1) {
                string str = "";
                while(count) {
                    str.push_back (count%10 + '0');
                    count /= 10;
                }

                for(int i=str.length()-1; i>=0; i--) {
                    ans.push_back(str[i]);
                }
            }
        }

        chars = ans;
        return ans.size();
    }
};