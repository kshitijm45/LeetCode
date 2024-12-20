// https://leetcode.com/problems/combination-sum

class Solution {
private:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& output, int sum, int i) {
        if(sum > target)
            return;
        if(i >= candidates.size()) {
            if(sum == target)
                ans.push_back(output);
            return;
        }
        solve(candidates, target, ans, output, sum, i+1);
        output.push_back(candidates[i]);
        solve(candidates, target, ans, output, sum+candidates[i], i);
        output.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates, target, ans, output, 0, 0);
        return ans;
    }
};