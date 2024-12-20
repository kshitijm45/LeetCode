// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    long long hourscount(vector<int> piles, int k) {
        int i = 0;
        long long hours = 0;
        for(int i=0;i<piles.size();i++) {
            hours += ceil(piles[i]/ (double)k);
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = *max_element(piles.begin(), piles.end());
        int left = 1, right = n;
        int mid = left + (right - left)/2;
        int ans = 0;
        while(left <= right) {
            long long hrs = hourscount(piles, mid);
            if(hrs <= h) {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
            mid = left + (right - left)/2;
        }
        return ans;
    }
};