// https://leetcode.com/problems/rearrange-array-elements-by-sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0, neg=1;
        int n = nums.size();
        vector<int> ans(n);
        for(auto it: nums) {
            if(it < 0) {
                ans[neg] = it;
                neg+=2;
            }
            else {
                ans[pos] = it;
                pos+=2;
            }
        }
        return ans;
    }
};