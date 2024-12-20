// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int rev=0, tmp=x;
        while(x) {
            if(rev > INT_MAX/10)
                return false;
            rev = rev*10 + x%10;
            x/=10;
        }
        if(tmp == rev)
            return true;
        return false;
    }
};