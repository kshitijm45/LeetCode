// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target < nums[0])
            return 0;
        int n = nums.size();
        if(target > nums[n-1])
            return n;
        int left=0,right=n-1;
        int mid = left + (right - left)/2;
        while(left <= right) {
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
            mid = left + (right - left)/2;
        }
        return left;
    }
};