class Solution {
public:
    bool isPalindrome(int x) {
        int reverse=0, copy=x;
        if (x<0) return false;
        while(x!=0){
            int dig= x%10;
            x=x/10;
            if (reverse >INT_MAX/10 || reverse<INT_MIN/10) return 0;
            reverse= reverse*10+ dig;
        }
        if(copy == reverse)return true;
        return false;
    }
};