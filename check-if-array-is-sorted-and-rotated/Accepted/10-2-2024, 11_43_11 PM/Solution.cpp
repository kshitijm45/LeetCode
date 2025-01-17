// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int invcount = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i-1] > nums[i])
                invcount++;
        }
        if(nums[n-1] > nums[0])
            invcount++;
        return invcount <= 1;
    }
};