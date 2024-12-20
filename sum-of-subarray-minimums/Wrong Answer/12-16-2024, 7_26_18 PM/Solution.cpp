// https://leetcode.com/problems/sum-of-subarray-minimums

class Solution {
const int MOD = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        long long sum = 0;
        int n = arr.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty())
                left[i] = st.top();
            st.push(i);
        }

        st = stack<int>();

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty())
                right[i] = st.top();
            st.push(i);
        }

        for(int i=0; i<n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;
            long long contribution = (leftCount * rightCount % MOD) * arr[i] % MOD;
            sum = (sum + contribution) % MOD;
        }

        return sum;
    }
};