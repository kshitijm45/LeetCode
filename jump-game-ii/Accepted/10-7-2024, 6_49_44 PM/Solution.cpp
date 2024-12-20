// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int goal = n - 1;
        int i = 0;
        int count = 0;
        while(goal != 0) {
            if(i + nums[i] >= goal) {
                goal = i;
                count++;
                i=0;
            }
            else
                i++;
        }
        return count;
    }
};