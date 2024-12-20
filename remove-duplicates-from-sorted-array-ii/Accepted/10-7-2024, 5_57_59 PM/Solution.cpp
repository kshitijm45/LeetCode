// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return n;
        int i=2;
        for(int j=2;j<n;j++) {
            if(nums[j] == nums[i-2]) 
                continue;
            nums[i++] = nums[j];
        }
        return i;
    }
};