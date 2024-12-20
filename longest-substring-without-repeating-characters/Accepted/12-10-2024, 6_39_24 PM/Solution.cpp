// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0;
        int maxlen = 0;
        vector<char> countarr(128, 0);
        while(right < s.length()) {
            while(countarr[s[right]] != 0) {
                countarr[s[left]] = 0;
                left++;
            }
            countarr[s[right]] = 1;
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};