// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right = nums.size()-1;
        if(nums[right] > nums[0])
            return nums[0];
        int mid = left + (right - left)/2;
        while(left < right) {
            if(nums[mid] >= nums[0])
                left = mid + 1;
            else
                right = mid;
            mid = left + (right - left)/2;
        }
        return nums[left];
    }
};