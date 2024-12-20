// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num: nums)
            st.insert(num);
        int maxLen=0, len=0;
        for(int num: nums) {
            len = 0;
            int i=0;
            if(st.find(num-1) == st.end()) {
                while(st.find(num+i) != st.end()) {
                    len++;
                    i++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};