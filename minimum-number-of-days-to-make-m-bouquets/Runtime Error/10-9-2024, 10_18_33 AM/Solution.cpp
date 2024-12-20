// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    int calcBouqets(vector<int>& bloomDay, int k, int days) {
        int curr=0, total=0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= days) {
                curr+=1;
                if(curr == k) {
                    total++;
                    curr = 0;
                }
            }
            else
                curr = 0;
        }
        return total;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(k*m > n)
            return -1;
        int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());
        int mid = left + (right - left)/2;
        int ans = 0;
        while(left <= right) {
            int boqs = calcBouqets(bloomDay, k, mid);
            if(boqs >= m) {
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