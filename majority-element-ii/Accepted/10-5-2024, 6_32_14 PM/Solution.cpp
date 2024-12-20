// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int c1 = 0, c2 = 0;
        for(auto it: nums) {
            if(c1 == 0 && it != ele2) {
                ele1 = it;
                c1 = 1;
            }
            else if(c2 == 0 && it != ele1) {
                ele2 = it;
                c2 = 1;
            }
            else if(it == ele1)
                c1++;
            else if(it == ele2)
                c2++;
            else {
                c1--;
                c2--;
            }
        }
        c1=0;
        c2=0;
        for(auto it: nums) {
            if(it == ele1)
                c1++;
            if(it == ele2)
                c2++;
        }
        int mini = floor(n/3);
        if(c1 > mini)
            ans.push_back(ele1);
        if(c2 > mini)
            ans.push_back(ele2);
        return ans;
    }
};