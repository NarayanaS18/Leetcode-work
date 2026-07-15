class Solution {
public:

    int f(int idx, vector<int> &dp){
        if(idx == 0) return 1;
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];
        int j1 = f(idx-1, dp);
        int j2 = f(idx-2, dp);

        return dp[idx] = j1+j2;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            int j1 = dp[i-1];
            int j2 = dp[i-2];
            dp[i] = j1 + j2;
        }
        return dp[n];
    }
};