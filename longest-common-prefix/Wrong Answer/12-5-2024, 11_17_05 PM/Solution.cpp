// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i = 0, flag=0;
        while(i < strs[0].size()) {
            char c = strs[0][i];
            for(int j=1; j<strs.size(); j++) {
                if(i < strs[j].size() && strs[j][i] != c)
                    return ans;
            }
            ans+=c;
            i++;
        }
        return ans;
    }
};