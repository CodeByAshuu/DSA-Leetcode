class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for(int p : pushed){
            st.push(p);
            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }

        if(st.empty()){
            return true;
        }
        return false;
    }
};