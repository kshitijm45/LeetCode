// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int i, n = num.length();
        string ans;
        for(int i=0; i<n ;i++) {
            while(!st.empty() && k>0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        for(i=0; i<ans.size(); i++) {
            if(ans[i] != '0')
                break;
        }
        return i == ans.size() ? "0" : ans.substr(i);
    }
};