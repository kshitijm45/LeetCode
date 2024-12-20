// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int left=0, right=1;
        while(right < intervals.size()) {
            if(intervals[right][0] > intervals[left][1]) {
                vector<int> temp = {intervals[left][0], intervals[right-1][1]};
                ans.push_back(temp);
                left = right;
            }
            else
                right++;
        }
        ans.push_back({intervals[left][0], intervals[right-1][1]});
        return ans;
    }
};