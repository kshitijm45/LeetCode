// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        int left=0, right=n-1;
        int mid = left+(right-left)/2;
        int leftmost = -1, rightmost = -1;
        while(left<=right) {
            if(nums[mid] == target) {
                leftmost = mid;
                right = mid-1;
            }
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
            mid = left+(right-left)/2;
        }
        ans.push_back(leftmost);
        left=0, right=n-1;
        mid = left+(right-left)/2;
        while(left<=right) {
            if(nums[mid] == target) {
                rightmost = mid;
                left = mid+1;
            }
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
            mid = left+(right-left)/2;
        }
        ans.push_back(rightmost);
        return ans;
    }
};