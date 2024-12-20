// https://leetcode.com/problems/binary-subarrays-with-sum

class Solution {
private:
    int lessThanSum(vector<int>& nums, int goal) {
        if(goal < 0)
            return 0;
        int left = 0, right = 0, sum = 0;
        int count = 0;
        while(right < nums.size()) {
            sum+=nums[right];
            while(sum > goal) {
                sum-=nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return lessThanSum(nums, goal) - lessThanSum(nums, goal-1);
    }
};