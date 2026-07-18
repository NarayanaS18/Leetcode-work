class Solution {
public:

    int f(int n, vector<int> &dp){
        if(n == 0 || n == 1) return n;
        if(n == 2) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = f(n-1, dp) + f(n-2, dp) + f(n-3, dp);
    }

    int tribonacci(int n) {
        if(n == 0 || n == 1) return n;
        if(n == 2) return 1;

        int prev3 = 0, prev2 = 1, prev = 1;

        for(int i=3; i<=n; i++){
            int cur = prev + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};