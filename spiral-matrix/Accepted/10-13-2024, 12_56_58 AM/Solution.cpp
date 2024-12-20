// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;
        int total = m*n;
        int count = 0;
        while(count < total) {
            for(int i = left; i <= right && count < total; i++) {
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            for(int i = top; i <= bottom && count < total; i++) {
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;
            for(int i = right; i >= left && count < total; i--) {
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;
            for(int i = bottom; i >= top && count < total; i--) {
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }
        return ans;
    }
};