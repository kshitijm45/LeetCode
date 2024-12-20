// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int curr = 0;
        for(auto it: s) {
            if(it == '(') {
                curr++;
                maxi = max(maxi, curr);
            }
            else if(it == ')')
                curr--;
        }
        return maxi;
    }
};