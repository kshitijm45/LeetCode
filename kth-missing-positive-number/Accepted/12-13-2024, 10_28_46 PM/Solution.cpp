// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left=0, right=arr.size()-1;
        int mid;
        while(left <= right) {
            mid = left + (right - left)/2;
            if(arr[mid] - mid - 1 >= k)
               right = mid-1;
            else
                left = mid+1;
        }
        return left + k;
    }
};