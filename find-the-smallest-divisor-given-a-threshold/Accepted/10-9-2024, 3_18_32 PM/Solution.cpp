// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    long long findResult(vector<int>& nums, int divisor) {
        long long result = 0;
        for(int i=0; i<nums.size(); i++) {
            result += ceil(nums[i]/(double)divisor);
        }
        return result;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1, right=*max_element(nums.begin(), nums.end());
        int mid = left + (right - left)/2;
        while(left <= right) {
            long long x = findResult(nums, mid);
            if(x <= threshold) {
                right = mid - 1;
            }
            else
                left = mid + 1;
            mid = left + (right - left)/2;
        }
        return left;
    }
};