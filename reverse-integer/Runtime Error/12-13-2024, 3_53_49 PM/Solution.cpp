// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int sign = x>0 ? 1 : -1;
        x=abs(x);
        while(x > 0) {
            int dig = x % 10;
            if(rev >= INT_MAX/10)
                return 0;
            rev = rev*10 + dig;
            x/=10;
        }
        return sign*rev;
    }
};