class Solution {
public:
    bool isPalindrome(string str) {
        int start = 0;
        int end = str.length() - 1;

        while(start < end) {
            if(str[start] != str[end]) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++) {
            if(isPalindrome(words[i])) {
                return words[i];
            }
        }

        return "";
    }
};