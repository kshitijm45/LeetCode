// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        int left = 0, right = 0;
        int total = 0, curr = 0;
        unordered_map<int, int> mp;
        while(right < nums.size()) {
            if(mp[nums[right]] == 0)
                curr++;
            mp[nums[right]]++;
            while(curr > k) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0)
                    curr--;
                left++;
            }
            total+=(right - left + 1);
            right++;
        }
        return total;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atMost(nums, k) - atMost(nums, k-1);
    }
};