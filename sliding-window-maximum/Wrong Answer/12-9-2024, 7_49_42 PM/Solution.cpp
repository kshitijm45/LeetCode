// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<k; i++) {
             if(dq.empty())
                dq.push_back(i);
            else {
                while(!dq.empty() && nums[dq.front()] <= nums[i])
                    dq.pop_front();
                dq.push_back(i);
            }
        }
        ans.push_back(nums[dq.front()]);
        for(int i=k; i<nums.size(); i++) {
            if(i - dq.front() >= k)
                dq.pop_front();
            if(dq.empty())
                dq.push_back(i);
            else {
                while(!dq.empty() && nums[dq.front()] <= nums[i])
                    dq.pop_front();
                dq.push_back(i);
            }
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};