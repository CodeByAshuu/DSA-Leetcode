class Solution {
public:

    int fibo(int n , vector<int>& dp){
        if(n == 0){
            return 0;
        }
        dp[0] = 0;
        dp[1] = 1;

        for(int t = 2; t <= n; t++){
            dp[t] = dp[t-1] + dp[t-2];
        }
        
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n+1);
        return fibo(n, dp);
    }
};