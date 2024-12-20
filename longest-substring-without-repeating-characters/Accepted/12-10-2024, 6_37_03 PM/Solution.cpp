// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0;
        int maxlen = 0;
        unordered_set<char> st;
        while(right < s.length()) {
            while(st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};