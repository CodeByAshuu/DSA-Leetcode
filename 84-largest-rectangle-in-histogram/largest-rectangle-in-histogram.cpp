class Solution {
public:
    vector<int> previousSmaller(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> prev(n);
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                prev[i] = -1;
            }else{
                prev[i] = st.top();
            }
            st.push(i);
        }
        return prev;
    }

    vector<int> nextSmaller(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> next(n);
        
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                next[i] = n;
            }else{
                next[i] = st.top();
            }
            st.push(i);
        }
        return next;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = previousSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            int width = next[i] - prev[i] - 1;
            int area = width * heights[i];
            ans = max(ans, area);
        }

        return ans;
    }
};