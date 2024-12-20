// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int product = 1;
        for(int i=0; i < nums.size(); i++) {
            product *= nums[i];
            if(product > maxi)
                maxi = product;
            if(product < 0)
                product = 1;
        }
        return maxi;
    }
};