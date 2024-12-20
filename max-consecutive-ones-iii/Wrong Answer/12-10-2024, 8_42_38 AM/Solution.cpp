// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int n = nums.size();
        int zerocount = 0, maxlen = 0;
        while(right < n) {
            if(nums[right] == 1)
                right++;
            else {
                zerocount++;
                if(zerocount <= k)
                    right++;
                else {
                    maxlen = max(maxlen, right - left + 1);
                    while(nums[left] != 0) {
                        left++;
                    }
                    left++;
                    zerocount--;
                    right++;
                }
            }
        }
        maxlen = max(maxlen, right - left - 1);
        return maxlen-1;
    }
};