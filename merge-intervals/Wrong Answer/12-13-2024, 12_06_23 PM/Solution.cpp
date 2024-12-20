// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int left=0, right=1;
        int rightlimit = INT_MIN;
        while(right < intervals.size()) {
            if(intervals[right][0] > intervals[left][1]) {
                vector<int> temp = {intervals[left][0], rightlimit};
                ans.push_back(temp);
                left = right;
            }
            else {
                rightlimit=max(rightlimit, intervals[right][1]);
                right++;
            }
        }
        ans.push_back({intervals[left][0], rightlimit});
        return ans;
    }
};