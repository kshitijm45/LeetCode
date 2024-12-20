// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int i, n = num.length();
        string ans;
        if(k == n)
            return "0";
        for(i=0; i < n; i++) {
            if(k <= 0)
                break;
            if(st.empty())
                st.push(num[i]);
            else if(st.top() > num[i]) {
                st.pop();
                st.push(num[i]);
                k--;
            }
            else
                k--;
        }
        while(i < n)
            st.push(num[i++]);
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        return i == ans.size() ? "0" : ans.substr(i);
    }
};