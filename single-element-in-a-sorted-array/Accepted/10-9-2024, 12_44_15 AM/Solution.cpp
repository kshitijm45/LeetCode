// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(nums[0] != nums[1])
            return nums[0];
        if(nums[n-2] != nums[n-1])
            return nums[n-1];
        int left = 0, right = n - 1;
        int mid = left + (right - left)/2;
        while(left <= right) {
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            else if((mid%2 != 0 && nums[mid-1] != nums[mid]) || (mid%2 == 0 && nums[mid-1] == nums[mid]))
                right = mid - 1;
            else
                left = mid + 1;
            mid = left + (right - left)/2;
        }
        return -1;
    }
};