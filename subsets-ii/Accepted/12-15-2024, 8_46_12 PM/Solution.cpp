// https://leetcode.com/problems/subsets-ii

class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, int i) {
        ans.push_back(output);
        for(int j=i; j<nums.size(); j++) {
            if(j > i && nums[j] == nums[j-1])
                continue;
            output.push_back(nums[j]);
            solve(nums,ans,output,j+1);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());
        solve(nums,ans,output,0);
        return ans;
    }
};