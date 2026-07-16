class Solution {
public:

    int f(int n, vector<int>& dp){
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n]; 
        return dp[n] = f(n-1, dp) + f(n-2, dp);
    }

    int fib(int n) {
        // vector<int> dp(n+1, 0);
        if(n == 0 || n == 1) return n;
        int prev2 = 0, prev = 1;
        for(int i=2; i<=n; i++){
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};