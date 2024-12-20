// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for(int i=1; i<=numRows; i++) {
            vector<int> tmp(i);
            tmp[0] = tmp[i-1] = 1;
            for(int j=1; j<i-1; j++) {
                tmp[j] = pascal[i-2][j-1] + pascal[i-2][j];
            }
            pascal.push_back(tmp);
        }
        return pascal;
    }
};