int setBits(int a) {
    int result = 0;
    
    while(a>0) {
        a &= a-1;
        result++;
    }
    
    return result;
}

bool compare(int a, int b) {
    int resulta = setBits(a);
    int resultb = setBits(b);
        
    if(resultb==resulta) {
        return a<b;
    }
    
    return resultb>resulta;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};