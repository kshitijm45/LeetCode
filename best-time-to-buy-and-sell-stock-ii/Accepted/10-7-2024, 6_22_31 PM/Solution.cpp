// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0;
        for(int i=1;i<n;i++) {
            if(prices[i] > prices[i-1])
                maxprofit += prices[i] - prices[i-1];
        }
        return maxprofit;
    }
};