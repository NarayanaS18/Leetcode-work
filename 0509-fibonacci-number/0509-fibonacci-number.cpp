class Solution {
public:

    int f(int i, vector<int> &dp){
        if(i == 0 || i == 1) return i;
        if(dp[i] != -1) return dp[i];
        return dp[i] = f(i-1, dp) + f(i-2, dp);
    }

    int fib(int n) {
        if(n <= 1) return n;
        int prev2 = 0, prev = 1;
        for(int i=2; i<=n; i++){
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};