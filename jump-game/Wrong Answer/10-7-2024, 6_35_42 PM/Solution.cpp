// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-2;i>=0;i--) {
            if(nums[i] >= (n-1-i)){
                return true;
            }
        }
        return false;
    }
};