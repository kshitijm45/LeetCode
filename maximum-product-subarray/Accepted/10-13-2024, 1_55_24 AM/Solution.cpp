// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int maxprod = nums[0], minprod = nums[0];
        for(int i=1; i < nums.size(); i++) {
            if(nums[i] < 0)
                swap(maxprod, minprod);
            maxprod = max(nums[i], nums[i] * maxprod);
            minprod = min(nums[i], nums[i] * minprod);
            maxi = max(maxi, maxprod);
        }
        return maxi;
    }
};