// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    int calcDays(vector<int>& weights, int c) {
        int days = 0;
        long long curr = 0;
        for(int i=0;i<weights.size();i++) {
            if(curr + weights[i] > c) {
                days+=1;
                curr = 0;
            }
            curr += weights[i];
        }
        if(curr > 0)
            days+=1;
        // cout << "capacity: " << c << endl;
        // cout << "days: " << days << endl;
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()), right = accumulate(weights.begin(),weights.end(), 0);
        int mid = left + (right - left)/2;
        while(left <= right) {
            int x = calcDays(weights, mid);
            if(x <= days)
                right = mid - 1;
            else
                left = mid + 1;
            mid = left + (right - left)/2;
        }
        return left;
    }
};