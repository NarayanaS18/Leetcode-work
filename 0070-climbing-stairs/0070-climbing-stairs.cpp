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
        int prev2 = 1, prev = 1;
        int jump1 = 0, jump2 = 0;
        for(int i=1; i<=n; i++){
            jump1 = prev;
            if(i > 1) jump2 = prev2;
            int cur = jump1 + jump2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};