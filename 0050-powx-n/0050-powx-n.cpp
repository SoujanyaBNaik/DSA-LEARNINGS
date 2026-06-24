class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long bin = n;
        if( n<0) {
            x=1/x;
            bin= -bin;
        }
        while(bin> 0){
            if( bin%2 ==1){
                ans *=x;
            }
            x=x*x;
            bin =bin/2;
        }
     return ans;
    }
};