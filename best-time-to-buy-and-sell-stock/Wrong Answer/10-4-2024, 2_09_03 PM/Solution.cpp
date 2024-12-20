// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i=0, j=n-1;
        int profit=0,maxprofit=0;
        while(i<j) {
            profit=prices[j] - prices[i];
            if(profit < 0) {
                i++;
                continue;
            }
            if(profit > maxprofit)
                maxprofit = profit;
            j--;
        }
        return maxprofit;
    }
};