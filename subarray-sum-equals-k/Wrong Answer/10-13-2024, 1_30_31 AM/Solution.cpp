// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int total=0;
        int sum = 0;
        mp[0] = 1;
        for(int i=0; i < nums.size(); i++) {
            sum+=nums[i];
            int rem = sum - k;
            if(mp.find(rem) != mp.end())
                total++;
            mp[sum]++;
        }
        return total;
    }
};