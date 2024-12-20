// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
private:
    vector<int> nextSmallerElement(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

private:
    vector<int> prevSmallerElement(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextSmallerElement(heights);
        vector<int> prev = prevSmallerElement(heights);
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int length = heights[i];
            if(next[i] == -1)
                next[i] = n;
            int breadth = next[i] - prev[i] - 1;
            int newarea = length * breadth;
            area = max(area, newarea);
        }
        return area;
    }
};