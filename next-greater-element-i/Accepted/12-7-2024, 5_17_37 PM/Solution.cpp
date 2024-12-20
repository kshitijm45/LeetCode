// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        vector<int> ans(n1);
        stack<int> st;
        unordered_map<int, int> mp;
        int n2 = nums2.size();
        for(int i=n2-1; i>=0; i--) {
            while(!st.empty() && st.top() <= nums2[i])
                st.pop();
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        for(int j=0; j<n1; j++) {
            ans[j] = mp[nums1[j]];
        }
        return ans;
    }
};