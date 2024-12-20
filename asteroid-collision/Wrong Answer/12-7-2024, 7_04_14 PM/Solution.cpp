// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int flag = 0, i=0;
        for(auto it: asteroids) {
            flag = 0;
            if(st.empty())
                st.push(it);
            else if(it * st.top() < 0) {
                while(!st.empty() && (it * st.top() < 0)) {
                    if(abs(st.top()) > abs(it)) {
                        flag = 1;
                        break;
                    }
                    else if(abs(st.top()) == abs(it)) {
                        st.pop();
                        flag = 1;
                        break;
                    }
                    else
                        st.pop();
                }
                if(!flag)
                    st.push(it);
            }   
            else
                st.push(it);
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};