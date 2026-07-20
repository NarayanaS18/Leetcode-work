class Solution {
public:

    int f(int idx, vector<int>& cost, vector<int>& dp){
        int n = cost.size();
        if(idx == n-1) return cost[idx];
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int jump1 = cost[idx] + f(idx+1, cost, dp);
        int jump2 = cost[idx] + f(idx+2, cost, dp);
        return dp[idx] = min(jump1, jump2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        dp[n-1] = cost[n-1];
        for(int i=n-2; i>=0; i--){
            int jump1 = cost[i] + dp[i+1];
            int jump2 = cost[i];
            if(i+2 < n){
                jump2 += dp[i+2];
            }
            dp[i] = min(jump1, jump2);
        } 
        return min(dp[0], dp[1]);
    }
};