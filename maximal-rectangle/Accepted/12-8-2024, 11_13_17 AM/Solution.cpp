// https://leetcode.com/problems/maximal-rectangle

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int largestArea(vector<int> &nums) {
        int n=nums.size();
        vector<int> prev = prevSmallerElement(nums);
        vector<int> next = nextSmallerElement(nums);
        int area = 0;
        for(int i=0; i<n; i++) {
            int length = nums[i];
            if(next[i] == -1)
                next[i] = n;
            int breadth = next[i] - prev[i] - 1;
            area = max(area, length * breadth);
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> row(matrix[0].size(),0);
        int area = 0;
        for(int i = 0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size();j++) {
                if(matrix[i][j] == '1')
                    row[j] += 1;
                else
                    row[j] = 0;
            }
            area = max(area, largestArea(row));
        }
        return area;
    }
};