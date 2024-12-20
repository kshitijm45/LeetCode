// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool check(string s, int start, int end) {
        if(start >= end)
            return true;
        if(!isalnum(s[start]))
            return check(s, start+1, end);
        if(!isalnum(s[end]))
            return check(s, start, end-1);
        if(s[start] != s[end])
            return false;
        return check(s, start+1, end-1);
    }

    bool isPalindrome(string s) {        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return check(s, 0, s.length()-1);
    }
};