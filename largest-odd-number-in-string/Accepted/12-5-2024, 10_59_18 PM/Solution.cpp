// https://leetcode.com/problems/largest-odd-number-in-string

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        while(n > 0) {
            if((num[n-1] - '0') % 2 != 0)
                return num.substr(0, n);
            else
                n--;
        }
        return "";
    }
};