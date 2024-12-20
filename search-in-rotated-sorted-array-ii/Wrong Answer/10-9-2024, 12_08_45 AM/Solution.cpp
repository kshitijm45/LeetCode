// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    int pivot(vector<int>& nums) {
        int left=0, right = nums.size()-1;
        int mid = left + (right - left)/2;
        while(left < right) {
            if(nums[mid] >= nums[0])
                left = mid + 1;
            else
                right = mid;
            mid = left + (right - left)/2;
        }
        return left;
    }

    bool search(vector<int>& nums, int target) {
        int p = pivot(nums);
        int left, right;
        int n = nums.size();
        if(target >= nums[p] && target <= nums[n-1]) {
            left = p;
            right = n - 1;
        }
        else {
            left = 0;
            right = p-1;
        }
        int mid = left + (right - left)/2;
        while(left <= right) {
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
            mid = left + (right - left)/2;
        }
        return false;
    }
};