// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0, sum = 0, max = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(sum == 0)
                start = i;
            sum+=nums[i];
            if(sum > max)
                max = sum;
            if(sum < 0)
                sum = 0;
        }
        return max;
    }
};