// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gpoint = 0, spoint = 0;
        while(gpoint < n && spoint < m) {
            if(g[gpoint] <= s[spoint])
                gpoint++;
            spoint++;
        }
        return gpoint;
    }
};