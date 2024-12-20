// https://leetcode.com/problems/remove-outermost-parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int i=0;
        int bal=0;
        while(i < s.size()) {
            if(s[i] == '(') {
                i++;
                while(true) {
                    if(s[i] == '(') {
                        ans+='(';
                        bal++;
                        i++;
                    }
                    else {
                        if(!bal) {
                            i++;
                            break;
                        }
                        else {
                            ans+=')';
                            bal--;
                            i++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};