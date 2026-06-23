class Solution {
public:
    int helper( int n, vector<int>& memo){
        if( n == 0 || n == 1) return n;
        if( memo[n] != -1) return memo[n];
        memo[n]= helper(n-2, memo)+ helper(n-1, memo);
        return memo[n];
    }
    int fib(int n) {
       vector<int> memo(n+1,-1);
       return helper(n, memo);
        
    }
};