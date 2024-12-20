// https://leetcode.com/problems/combination-sum-iii

class Solution {
private:
    void solve(int k, int n, vector<vector<int>>& ans, vector<int>& output, int sum, int i) {
        if(sum > n)
            return;
        if(i >= 10) {
            if(sum == n && output.size() == k)
                ans.push_back(output);
            return;
        }
        solve(k,n,ans,output,sum,i+1);
        output.push_back(i);
        solve(k,n,ans,output,sum+i,i+1);
        output.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(k,n,ans,output,0,1);
        return ans;
    }
};