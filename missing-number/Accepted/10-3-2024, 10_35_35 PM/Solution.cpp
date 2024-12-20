// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(auto it: nums) {
            result ^= it;
        }
        for(int i=1; i <= n; i++)
            result ^= i;
        return result;
    }
};