// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int n = cardPoints.size();
        if(n <= k)
            return total;
        int left=0, right = n-k-1;
        int sum=0, ans=0;
        for(int i=0; i<n-k-1; i++)
            sum+=cardPoints[i];
        while(right < n) {
            sum+=cardPoints[right];
            ans = max(ans, total-sum);
            sum-=cardPoints[left];
            left++;
            right++;
        }
        return ans;
    }
};