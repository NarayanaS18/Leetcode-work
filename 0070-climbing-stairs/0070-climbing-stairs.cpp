class Solution {
public:

    int f(int idx, vector<int> &dp){
        if(idx == 0) return 1;
        int jump1 = 0, jump2 = 0;
        if(dp[idx] != -1) return dp[idx];
        if(idx > 0) jump1 = f(idx-1, dp);
        if(idx > 1) jump2 = f(idx-2, dp);
        return dp[idx] = jump1 + jump2;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};