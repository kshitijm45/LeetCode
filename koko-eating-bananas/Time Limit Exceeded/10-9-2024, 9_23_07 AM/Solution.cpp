// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    int hourscount(vector<int> piles, int k) {
        int i = 0;
        int hours = 0;
        while(i < piles.size()) {
            if(piles[i] <= k) {
                i++;
            }
            else {
                piles[i] -= k;
            }
            hours+=1;          
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = *max_element(piles.begin(), piles.end());
        int left = 1, right = n;
        int mid = left + (right - left)/2;
        int ans = 0;
        while(left <= right) {
            int hrs = hourscount(piles, mid);
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