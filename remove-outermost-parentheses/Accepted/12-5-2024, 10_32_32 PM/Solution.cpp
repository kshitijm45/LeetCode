// https://leetcode.com/problems/remove-outermost-parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int i=0;
        stack<char> st;
        while(i < s.size()) {
            if(s[i] == '(') {
                i++;
                while(true) {
                    if(s[i] == '(') {
                        ans+='(';
                        st.push('(');
                        i++;
                    }
                    else {
                        if(st.empty()) {
                            i++;
                            break;
                        }
                        else {
                            ans+=')';
                            st.pop();
                            i++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};