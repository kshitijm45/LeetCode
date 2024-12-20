// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int j=0;j<n;j++) {
            temp[(j+k)%n] = nums[j];
        }
        nums = temp;
    }
};