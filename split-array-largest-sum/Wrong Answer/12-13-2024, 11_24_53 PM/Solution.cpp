// https://leetcode.com/problems/split-array-largest-sum

class Solution {
private:
    bool isPossible(vector<int>& nums, int k, int maxsum) {
        int sum = 0, cnt=1;
        for(auto it: nums) {
            sum+=it;
            if(sum > maxsum) {
                cnt++;
                sum = it;
            }
        }
        if(cnt <= k)
            return true;
        return false;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end()), right = accumulate(nums.begin(), nums.end(), 0);
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(isPossible(nums, k, mid))
                right = mid-1;
            else
                left = mid + 1;
        }
        return left;
    }
};