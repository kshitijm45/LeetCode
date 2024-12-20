// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount = 0, currcount = 0;
        for(auto it: nums) {
            if(it == 1)
                currcount++;
            else {
                if(currcount > maxcount)
                    maxcount = currcount;
                currcount = 0;
            }
        }
        if(currcount > maxcount)
            return currcount;
        return maxcount;
    }
};