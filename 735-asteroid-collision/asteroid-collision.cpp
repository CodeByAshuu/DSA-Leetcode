class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int meteor : asteroids){
            bool alive = true;
            while(!st.empty() && st.top() > 0 && meteor < 0){
                if(st.top() < -meteor){
                    st.pop();
                }else if(st.top() == -meteor){
                    st.pop();
                    alive = false;
                    break;
                }else{
                    alive = false;
                    break;
                }
            }

            if(alive){
                st.push(meteor);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};