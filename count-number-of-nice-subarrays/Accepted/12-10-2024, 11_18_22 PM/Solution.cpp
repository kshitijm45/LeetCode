// https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution {
private:
    int atMost(vector<int>& nums, int k) {
        int nice = 0;
        int left=0, right=0;
        int oddcount=0;
        while(right < nums.size()) {
            if(nums[right] % 2 == 1)
                oddcount++;
            while(oddcount > k) {
                if(nums[left] % 2 == 1)
                    k++;
                left++;
            }
            nice += right - left + 1;
            right++;
        }
        return nice;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};