class Solution {
public:
    vector<int> nextSmaller(vector<int> &heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> answer(n);
        
        for(int i=n-1; i>=0; i--) {
            int item = heights[i];
            while(st.top() != -1 && heights[st.top()] >= item) st.pop();
            
            if(st.top() == -1) answer[i] = n;
            else answer[i] = st.top();
            
            st.push(i);
        }
        
        return answer;
    }
    
    vector<int> prevSmaller(vector<int> &heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> answer(n);
        
        for(int i=0; i<n; i++) {
            int item = heights[i];
            while(st.top() != -1 && heights[st.top()] >= item) st.pop();
            
            answer[i] = st.top();
            st.push(i);
        }
        
        return answer;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        
        vector<int> next = nextSmaller(heights, n);
        vector<int> prev = prevSmaller(heights, n);
        
        for(int i=0; i<n; i++) {
            if(next[i] == -1) next[i] = n;
            
            int length = heights[i];
            int breadth = next[i] - prev[i] - 1;
            
            int newArea = length * breadth;
            maxArea = max(newArea, maxArea);
        }
        
        return maxArea;
    }
};