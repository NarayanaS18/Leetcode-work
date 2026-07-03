class Solution {
public:

    int f(int idx, int n, vector<int>& cost, vector<int>& dp){
        if(idx == n) return 0;
        int jump1 = 0, jump2 = 0;
        if(dp[idx] != -1) return dp[idx];
        if(idx+1 <= n) jump1 = f(idx+1, n, cost, dp);
        if(idx+2 <= n) jump2 = f(idx+2, n, cost, dp);
        return dp[idx] = cost[idx] + min(jump1, jump2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(f(0, n, cost, dp), f(1, n, cost, dp));
    }
};